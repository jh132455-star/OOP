#pragma once
#include "UserInterface.h"
#include <iostream>
using namespace std;

class DungeonExplorerUI : public UserInterface
{
	virtual void ShowMenu() override;
	virtual UIType GetType() override;
};

