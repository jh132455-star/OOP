// TownUi.h
#pragma once
#include "UserInterface.h"

class TownUi : public UserInterface {
public:
    void ShowMenu() override;
    UIType GetType() override;
};