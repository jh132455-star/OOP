#pragma once
#include "GameEnum.h"

class StatusManager
{
public:
	StatusManager();
	StatusManager(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower, unsigned int exe);
	StatusManager(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower, ElementType elementType);

	unsigned int GetAttackPower();
	unsigned int GetDefensePower();
	unsigned int GetHp();
	unsigned int GetMp();
	unsigned int GetExe();
	void SetElementType(ElementType element);
	ElementType GetElementType();

	bool IsDead();

	void AddHp(unsigned int hp);
	void SubHp(unsigned int hp);
	
	void AddMp(unsigned int hp);
	void SubMp(unsigned int hp);

	void AddAttackPower(unsigned int attackPower);
	void SubAttackPower(unsigned int attackPower);

	void AddDefensePower(unsigned int defensePower);
	void SubDefensePower(unsigned int defensePower);

	void AddExe(unsigned int exe);
	void SubExe(unsigned int exe);
	
private:
	unsigned int hp;
	unsigned int mp;

	unsigned int attackPower;
	unsigned int defensePower;

	unsigned int exe;

	ElementType element = ElementType::NoStatement;
};