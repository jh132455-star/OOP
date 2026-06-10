// MpPotion.cpp
#include "MpPotion.h"

MpPotion::MpPotion(unsigned int amount)
    : amount(amount)
{
}

unsigned int MpPotion::Use()
{
    return amount;
}

ItemType MpPotion::GetItemType() const
{
    return ItemType::MpPotion;
}