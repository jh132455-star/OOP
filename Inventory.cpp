#include "Inventory.h"

Inventory::Inventory()
{
    inventorySize = 10;
}

Inventory::Inventory(size_t inventorySize)
    : inventorySize(inventorySize)
{
}

bool Inventory::InsertItem(ItemType item)
{
    unsigned int remainSlot = GetRemainSlot();

    if (remainSlot > 0)
    {
        inventory[item]++;
        return true;
    }
    return false;
}

ItemType Inventory::GetItem(ItemType type)
{

    return type; // ItemType 키만 있고 실제 포인터가 없음
}

size_t Inventory::GetRemainSlot()
{
    unsigned int totalCount = 0;
    for (auto& pair : inventory)
        totalCount += pair.second;

    size_t remainSize = inventorySize - totalCount;

    return remainSize;
}
