#pragma once
#include "Item.h"

class Consumable : public Item
{
public:
    virtual unsigned int Use() = 0;
};