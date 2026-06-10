#include "HpPotion.h"

HpPotion::HpPotion(unsigned int amount)
    : amount(amount)
{
}

unsigned int HpPotion::Use()
{
    return amount;
}

ItemType HpPotion::GetItemType() const
{
    return ItemType::HpPotion;
}