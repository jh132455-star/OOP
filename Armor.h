#pragma once// Armor.h
#pragma once
#include "Equipment.h"

class Armor : public Equipment
{
public:
    Armor(unsigned int defenseBonus);
    ItemType GetItemType() const override;
    unsigned int GetDefenseBonus();
private:
    unsigned int defenseBonus;
};

