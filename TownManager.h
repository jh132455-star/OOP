#pragma once
#include "Character.h"
#include "JobFactory.h"
class TownManager {
public:
    void EnterHospital(Character& character);
    void ChangeJob(Character& character);

private:
    JobFactory jobFactory;
};