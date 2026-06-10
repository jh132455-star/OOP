#pragma once
#include <iostream>
#include "GameEnum.h"
using namespace std;

class UserInterface
{
public:
	virtual void ShowMenu() = 0;
	virtual UIType GetType() = 0;
};