#pragma once
#include "Consumable.h"

class HpPotion : public Consumable
{
public:
    HpPotion(unsigned int amount);
    unsigned int Use() override;
    ItemType GetItemType() const override;

private:
    unsigned int amount;
};