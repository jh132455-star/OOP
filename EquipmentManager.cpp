// EquipmentManager.cpp
#include "EquipmentManager.h"

EquipmentManager::EquipmentManager()
    : weapon(nullptr), armor(nullptr)
{
}

bool EquipmentManager::EquipWeapon(Weapon* weapon)
{
    this->weapon = weapon;
    this->bonusAttackPower += weapon->GetAttackBonus();
    return true;
}

bool EquipmentManager::EquipArmor(Armor* armor)
{
    this->armor = armor;
    this->bonusDefensePower += armor->GetDefenseBonus();
    return true;
}

bool EquipmentManager::UnequipWeapon()
{
    if (this->weapon == nullptr)
        return false;

    this->weapon = nullptr;
    return true;
}

bool EquipmentManager::UnequipArmor()
{
    if (this->armor == nullptr)
        return false;

    this->armor = nullptr;
    return true;
}

unsigned int EquipmentManager::GetBonusAttackPower()
{
    return bonusAttackPower;
}

unsigned int EquipmentManager::GetBonusDefensePower()
{
    return bonusDefensePower;
}

Weapon* EquipmentManager::GetWeapon() const
{
    return weapon;
}

Armor* EquipmentManager::GetArmor() const
{
    return armor;
}