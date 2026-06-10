// EquipmentManager.h
#pragma once
#include "Weapon.h"
#include "Armor.h"

class EquipmentManager
{
public:
    EquipmentManager();

    bool EquipWeapon(Weapon* weapon);
    bool EquipArmor(Armor* armor);

    bool UnequipWeapon();
    bool UnequipArmor();

    unsigned int GetBonusAttackPower();
    unsigned int GetBonusDefensePower();

    Weapon* GetWeapon() const;
    Armor* GetArmor() const;

private:
    unsigned int bonusAttackPower = 0;
    unsigned int bonusDefensePower = 0;

    Weapon* weapon;
    Armor* armor;
};