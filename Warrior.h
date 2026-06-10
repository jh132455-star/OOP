#pragma once
#include "Job.h"

class Warrior : public Job {
public:
    virtual unsigned int UseSkill(unsigned int& currentMp) override;
};