#pragma once
#include "GameEnum.h"

class Item
{
public:
    virtual ~Item() = default;
    virtual ItemType GetItemType() const = 0;
protected:
    Item() = default;
};