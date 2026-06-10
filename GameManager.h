#pragma once
#include "UserInterface.h"
#include "GameContext.h"
#include "DungeonExplorer.h"
#include "TownManager.h"
#include "BattleSystem.h"

class GameManager
{
public:
	GameManager();
	void StartGame();
private:
	bool ProcessInput(int choice);

	void GenerateCharacter();

	std::unique_ptr<UserInterface> ui;
	DungeonExplorer dungeonExplorer;
	BattleSystem battleSystem;
	TownManager townManager;

	MonsterFactory monsterFactory;
	std::unique_ptr<Character> character;
};

