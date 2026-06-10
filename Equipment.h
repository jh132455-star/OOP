// Equipment.h
#pragma once
#include "Item.h"

class Equipment : public Item
{
public:
    ItemType GetItemType() const override = 0;
};