#pragma once
#include "GameEnum.h"

class WeaknessAttackJudge
{
public:
	WeaknessAttackJudge() =  default;
	bool Judge(ElementType attacker, ElementType defender);
};

