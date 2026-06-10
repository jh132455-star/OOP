// Weapon.cpp
#include "Weapon.h"
#include "StatusManager.h"

Weapon::Weapon(unsigned int attackBonus)
    : attackBonus(attackBonus)
{
}

/*void Weapon::Equip(StatusManager& statusManager)
{
    statusManager.AddAttackPower(attackBonus);
}

void Weapon::Unequip(StatusManager& statusManager)
{
    statusManager.SubAttackPower(attackBonus);
}*/

ItemType Weapon::GetItemType() const
{
    return ItemType::Weapon;
}

unsigned int Weapon::GetAttackBonus() const
{
    return attackBonus;
}
