// MonsterFactory.h
#pragma once
#include "Monster.h"
#include "GameEnum.h"
//#include "Item.h"

class MonsterFactory
{
public:
    Monster Create(MonsterType type);

private:
    std::map<ItemType, size_t> CreateDropList(MonsterType type);

    StatusManager CreateStatus(MonsterType type);
    ElementType   CreateElement(MonsterType type);
};