// Weapon.h
#pragma once
#include "Equipment.h"

class Weapon : public Equipment
{
public:
    Weapon(unsigned int attackBonus);
    ItemType GetItemType() const override;
    unsigned int GetAttackBonus() const;

private:
    unsigned int attackBonus;
};