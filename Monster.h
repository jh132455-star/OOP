#pragma once
#include <iostream>
#include "StatusManager.h"
#include "Attackable.h"
#include "Damageable.h"
#include <map>

class Monster : public Attackable , public Damageable
{
public:
	Monster();
	Monster(StatusManager status, ElementType element);
	void SetDropList(std::map<ItemType, size_t> dropList);

	unsigned int Attack() override;
	void TakeDamage(unsigned int damage) override;

	bool IsDead();

	ElementType GetElementType();
	unsigned int GetDefensePower();

	unsigned int GetExe();

	std::map<ItemType, size_t> GetDropList();
private:
	StatusManager statusManager;
	std::map<ItemType, size_t> dropList;
};