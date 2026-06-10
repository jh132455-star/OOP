// Equippable.h
#pragma once
#include "Weapon.h"
#include "Armor.h"

class Equippable
{
public:
    virtual void EquipWeapon(Weapon* weapon) = 0;
    virtual void EquipArmor(Armor* armor) = 0;
    virtual void UnequipWeapon() = 0;
    virtual void UnequipArmor() = 0;
    virtual ~Equippable() = default;
};