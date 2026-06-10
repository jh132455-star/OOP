// MonsterFactory.cpp
#include "MonsterFactory.h"

Monster MonsterFactory::Create(MonsterType type)
{
    StatusManager status = CreateStatus(type);
    ElementType   element = CreateElement(type);
    Monster monster(status, element);
    monster.SetDropList(CreateDropList(type));

    return monster;
}

std::map<ItemType, size_t> MonsterFactory::CreateDropList(MonsterType type)
{
    std::map<ItemType, size_t> dropList;

    switch (type)
    {
    case MonsterType::Slime:
        dropList[ItemType::HpPotion] = 1;
        break;
    case MonsterType::Goblin:
        dropList[ItemType::HpPotion] = 2;
        dropList[ItemType::MpPotion] = 1;
        break;
    case MonsterType::Dragon:
        dropList[ItemType::HpPotion] = 3;
        dropList[ItemType::MpPotion] = 2;
        dropList[ItemType::Weapon] = 1;
        dropList[ItemType::Armor] = 1;
        break;
    }

    return dropList;
}


StatusManager MonsterFactory::CreateStatus(MonsterType type)
{
    switch (type)
    {
    case MonsterType::Slime:
        return StatusManager(50, 0, 5, 2, 1);
    case MonsterType::Goblin:
        return StatusManager(80, 20, 12, 5, 5);
    case MonsterType::Dragon:
        return StatusManager(300, 100, 50, 30, 100);
    default:
        return StatusManager();
    }
}

ElementType MonsterFactory::CreateElement(MonsterType type)
{
    switch (type)
    {
    case MonsterType::Slime:
        return ElementType::Water;
    case MonsterType::Goblin:
        return ElementType::Earth;
    case MonsterType::Dragon:
        return ElementType::Fire;
    default:
        return ElementType::NoStatement;
    }
}