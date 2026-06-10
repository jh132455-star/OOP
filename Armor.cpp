// Armor.cpp
#include "Armor.h"
#include "StatusManager.h"

Armor::Armor(unsigned int defenseBonus)
    : defenseBonus(defenseBonus)
{
}

ItemType Armor::GetItemType() const
{
    return ItemType::Armor;
}

unsigned int Armor::GetDefenseBonus()
{
    return defenseBonus;
}
