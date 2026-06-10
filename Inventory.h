#pragma once
#include <map>
#include <iostream>

#include "Item.h"
class Inventory
{
public:
	Inventory();
	Inventory(size_t inventorySize);
	
	bool InsertItem(ItemType item);
	ItemType GetItem(ItemType type);

private:
	size_t GetRemainSlot();

	size_t inventorySize;
	std::map<ItemType, size_t> inventory;  // 아이템 종류 : 개수
};