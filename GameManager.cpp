#include "GameManager.h"
#include "MainUi.h"
#include "DungeonSelectUi.h"
#include "DungeonExplorerUI.h"
#include "TownUi.h"
#include "BattleUi.h"
GameManager::GameManager()
{
    this->ui = std::make_unique<MainUi>();
}

void GameManager::StartGame()
{
    int choice;
    while (true) 
    {
        ui->ShowMenu();
        cin >> choice;
        if (!ProcessInput(choice)) 
            return; // false면 종료
    }
}

bool GameManager::ProcessInput(int choice)
{
    switch (ui->GetType()) {

    case UIType::Main:
    {
        switch (choice) {
        case 0: GenerateCharacter(); break;
        case 1: ui = make_unique<TownUi>(); break;
        case 2: ui = make_unique<DungeonSelectUi>(); break;
        case 3: return false;
        default: cout << "잘못된 입력" << endl;
        }
        break;
    }

    case UIType::Town:
    {
        switch (choice) {
        case 0:
            cout << "\n직업 변경." << endl;
            townManager.ChangeJob(*character);
            break;
        case 1:
            cout << "\n캐릭터의 체력이 회복되었습니다." << endl;
            townManager.EnterHospital(*character);
            break;
        case 2:
            cout << "\n던전으로 이동합니다" << endl;
            ui = make_unique<DungeonSelectUi>();
            break;
        case 3:
            cout << "\n메인화면으로 돌아갑니다" << endl;
            ui = make_unique<MainUi>();
            break;
        default: cout << "잘못된 입력" << endl;
        }
        break;
    }

    case UIType::DungeonSelect:
    {
        switch (choice)
        {
        case 1:
            cout << "슬라임 던전에 입장합니다" << endl;
            dungeonExplorer.EnterDungeon(MonsterType::Slime);
            ui = make_unique<DungeonExplorerUI>();
            //dungeonExplorer.Explore(*character);
            break;
        case 2:
            cout << "고블린 던전에 입장합니다" << endl;
            dungeonExplorer.EnterDungeon(MonsterType::Goblin);
            ui = make_unique<DungeonExplorerUI>();
            //dungeonExplorer.Explore(*character);
            break;
        case 3:
            cout << "드래곤 던전에 입장합니다" << endl;
            dungeonExplorer.EnterDungeon(MonsterType::Dragon);
            ui = make_unique<DungeonExplorerUI>();
            //dungeonExplorer.Explore(*character);
            break;
        case 4:
            cout << "\n마을로 돌아갑니다" << endl;
            ui = make_unique<TownUi>();
            break;
        case 5:
            cout << "\n메인화면으로 돌아갑니다" << endl;
            ui = make_unique<MainUi>();
            break;
        default: cout << "잘못된 입력" << endl;
        }
        break;
    }

    case UIType::DungeonExplorer:
    {
        switch (choice) {
        case 1:
            cout << "\n던전 탐색." << endl;
            if (dungeonExplorer.Explore(*character)) 
            {
                battleSystem.SetMonster(monsterFactory.Create(dungeonExplorer.GetDungeonType()));
                ui = make_unique<BattleUi>();
            }
            break;
        case 2:
            cout << "\n마을로 돌아가기" << endl;
            ui = make_unique<DungeonSelectUi>();
            break;
        default: cout << "잘못된 입력" << endl;
        }
        break;
    }

    case UIType::Battle:
    {
        switch (choice) {
        case 1:
            cout << "\n일반공격 수행." << endl;
            battleSystem.PlayerAttack(*character);
            if (battleSystem.IsBattleOver(*character))
            {
                battleSystem.ResolveBattle(*character);
                ui = make_unique<DungeonExplorerUI>();
                break; 
            }
            battleSystem.DoMonsterAction(*character);
            break;
        case 2:
            cout << "\n스킬공격 수행" << endl;
            battleSystem.PlayerSkillAttack(*character);
            if (battleSystem.IsBattleOver(*character)) 
            {
                battleSystem.ResolveBattle(*character);
                ui = make_unique<DungeonExplorerUI>();
                break; 
            }
            battleSystem.DoMonsterAction(*character);
            break;
        case 3:
            cout << "\n마을로 도망간다" << endl;
            battleSystem.CleanUpBattle();
            ui = make_unique<TownUi>();
            break;
        default: cout << "잘못된 입력" << endl;
        }
        break;
    }

    }
    return true;
}

void GameManager::GenerateCharacter()
{
    if (character == nullptr)
    {
        cout << "\n캐릭터 생성 성공" << endl;
        cout << "\n";
        character = std::make_unique<Character>();
    }
}