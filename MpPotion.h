// MpPotion.h
#pragma once
#include "Consumable.h"

class MpPotion : public Consumable
{
public:
    MpPotion(unsigned int amount);
    unsigned int Use() override;
    ItemType GetItemType() const override;

private:
    unsigned int amount;
};