#pragma once
#include <iostream>
#include "GameEnum.h"
#include "WeaknessAttackJudge.h"
#include "Monster.h"
class Character;

class BattleSystem
{
public:
	BattleSystem() = default;
	//void Battle(Character& character, Monster& monster);
	unsigned int PlayerAttack(Character& character);
	unsigned int PlayerSkillAttack(Character& character);
	void BattleResult(Character& character, Monster& monster);
	void CleanUpBattle();
	void SetMonster(Monster monster);
	void ResolveBattle(Character& character);
	bool IsBattleOver(Character& character);
	void DoMonsterAction(Character& character);

private:
	unsigned int CalculateDamage(unsigned int pureDamage, unsigned int bonusAttackPower, unsigned int defensePower, ElementType attackerType, ElementType defenderType);
	void MonsterAttack(Character& character);

	WeaknessAttackJudge weaknessJudge;
	Monster currentMonster;
};

