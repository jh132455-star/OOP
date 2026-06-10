#pragma once
#include "UserInterface.h"
class MainUi : public UserInterface
{
public:
	virtual void ShowMenu() override;
	virtual UIType GetType() override;
};

