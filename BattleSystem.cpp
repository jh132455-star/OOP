#include "BattleSystem.h"
#include "Character.h"
#include "Monster.h"

//void BattleSystem::Battle(Character& character, Monster& monster)
//{
//	while (!character.IsDead() && !monster.IsDead())
//	{
//		unsigned int characterDamage = CalculateDamage(character.Attack(), character.GetBonusAttackPower(), monster.GetDefensePower(), character.GetElementType(), monster.GetElementType());
//			
//		monster.TakeDamage(characterDamage);
//
//		if (monster.IsDead())
//			break;
//
//		unsigned int monsterDamage = CalculateDamage(monster.Attack(), 0, character.GetDefensePower(), monster.GetElementType(), character.GetElementType());
//		character.TakeDamage(monsterDamage);
//	}
//
//	if (character.IsDead()) 
//	{
//		std::cout << "Character is Dead. Monster Win" << std::endl;
//	}
//	else 
//	{
//		//Drop템을 캐릭터가 가져가야됨.
//		auto dropList = monster.GetDropList();
//		character.AcquireItems(dropList);
//		character.AcquireExe(monster.GetExe());
//
//		std::cout << "Monster is Dead. Character Win" << std::endl;
//		std::cout << "경험치를 획득하였습니다. 획득한 경험치 : " << monster.GetExe() << std::endl;
//		std::cout << "캐릭터의 현재 경험치 : " << character.GetExe() << std::endl;
//	}
//}
unsigned int BattleSystem::PlayerAttack(Character& character)
{
	unsigned int damage = CalculateDamage(
		character.Attack(), character.GetBonusAttackPower(),
		currentMonster.GetDefensePower(),
		character.GetElementType(), currentMonster.GetElementType()
	);
	currentMonster.TakeDamage(damage);

	return damage;
}

unsigned int BattleSystem::PlayerSkillAttack(Character& character)
{
	if (!character.HasJob()) {
		std::cout << "No job assigned." << std::endl;
		return 0;
	}

	unsigned int currentMp = character.GetMp();
	unsigned int skillPower = character.GetJob()->UseSkill(currentMp);
	if (skillPower == 0) return 0;

	unsigned int damage = CalculateDamage(
		skillPower, 0,
		currentMonster.GetDefensePower(),
		character.GetElementType(), currentMonster.GetElementType()
	);
	currentMonster.TakeDamage(damage);

	return damage;
}

void BattleSystem::MonsterAttack(Character& character)
{
	unsigned int damage = CalculateDamage(
		currentMonster.Attack(), 0,
		character.GetDefensePower(),
		currentMonster.GetElementType(), character.GetElementType()
	);
	character.TakeDamage(damage);
}

void BattleSystem::BattleResult(Character& character, Monster& monster)
{
	if (character.IsDead())
	{
		std::cout << "Character is Dead. Monster Win" << std::endl;
	}
	else
	{
		auto dropList = monster.GetDropList();
		character.AcquireItems(dropList);
		character.AcquireExe(monster.GetExe());

		std::cout << "Monster is Dead. Character Win" << std::endl;
		std::cout << "EXP gained: " << monster.GetExe() << std::endl;
		std::cout << "Current EXP: " << character.GetExe() << std::endl;
	}
}

void BattleSystem::DoMonsterAction(Character& character)
{
	if (!currentMonster.IsDead())
		MonsterAttack(character);
}

void BattleSystem::CleanUpBattle()
{
}

void BattleSystem::SetMonster(Monster monster)
{
	currentMonster = monster;
}

void BattleSystem::ResolveBattle(Character& character)
{
	if (currentMonster.IsDead()) 
	{
		auto dropList = currentMonster.GetDropList();
		character.AcquireItems(dropList);
		character.AcquireExe(currentMonster.GetExe());

		std::cout << "Monster is Dead. Character Win" << std::endl;
		std::cout << "경험치를 획득하였습니다. 획득한 경험치 : " << currentMonster.GetExe() << std::endl;
		std::cout << "캐릭터의 현재 경험치 : " << character.GetExe() << std::endl;
	}
	else 
	{
		std::cout << "캐릭터가 사망하였습니다. 마을로 이동합니다" << currentMonster.GetExe() << std::endl;
	}
	
}

bool BattleSystem::IsBattleOver(Character& character)
{
	return currentMonster.IsDead() || character.IsDead();
}

unsigned int BattleSystem::CalculateDamage(unsigned int pureDamage, unsigned int bonusAttackPower, unsigned int defensePower, ElementType attackerType, ElementType defenderType)
{
	unsigned int finalAttackPower = pureDamage + bonusAttackPower;
	unsigned int damage = 0;

	if (weaknessJudge.Judge(attackerType, defenderType) == true)
	{
		std::cout << "상성이 좋습니다. 데미지가 2배가 됩니다." << std::endl;
		finalAttackPower *= 2;
	}

	if (defensePower >= finalAttackPower)
	{
		std::cout << "상당한 방어력입니다. 공격이 무력화됩니다." << std::endl;
		damage = 0;
	}
	else
		damage = finalAttackPower - defensePower;


	//디버프
	return damage;
}