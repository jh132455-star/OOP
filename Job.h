#pragma once
#include "SkillCapable.h"
class Job : public SkillCapable
{
public:
	virtual unsigned int UseSkill(unsigned int& currentMp) = 0;
};