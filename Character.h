#pragma once
#include <iostream>
#include "StatusManager.h"
#include "Attackable.h"
#include "Damageable.h"
#include "Inventory.h"
#include "Equippable.h"
#include "EquipmentManager.h"
#include "Job.h"

class Character : public Attackable, public Damageable, public Equippable
{
public:
	Character();
	Character(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower);

	unsigned int Attack() override;
	void TakeDamage(unsigned int damage) override;
	void TakeHp(unsigned int amount);
	void EquipWeapon(Weapon* weapon) override;
	void EquipArmor(Armor* armor) override;
	void UnequipWeapon() override;
	void UnequipArmor() override;

	void AcquireItems(std::map<ItemType, size_t> itemList);
	void AcquireExe(unsigned int exe);
	unsigned int GetBonusAttackPower();
	unsigned int GetBonusDefensePower();
	unsigned int GetExe();
	bool IsDead();
	bool HasJob();
	ElementType GetElementType();
	unsigned int GetDefensePower();
	unsigned int GetMp();
	Job* GetJob();
	bool SetJob(std::unique_ptr<Job> job);
private:
	std::unique_ptr<Job> job = nullptr;
	StatusManager statusManager;
	Inventory inventory;
	EquipmentManager equipmentManager;
	// @todo : 장비관리자 구현.
	// 무기 , 갑옷을 입을거임.
	// 무기 입으면 공격력증가.
	// 갑옷 입으면 방어력 증가.
};