#pragma once
#include "Job.h"
class Mage : public Job
{
	virtual unsigned int UseSkill(unsigned int& currentMp);
};

