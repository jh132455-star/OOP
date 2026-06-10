#include "StatusManager.h"

StatusManager::StatusManager()
{
	this->hp = 100;
	this->mp = 100;
	this->attackPower = 1;
	this->defensePower = 1;
}

StatusManager::StatusManager(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower, unsigned int exe)
	: hp(hp), mp(mp), attackPower(attackPower), defensePower(defensePower), exe(exe)
{
}

StatusManager::StatusManager(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower, ElementType elementType)
    : hp(hp), mp(mp), attackPower(attackPower), defensePower(defensePower), element(elementType)
{
}

unsigned int StatusManager::GetAttackPower()
{
	return this->attackPower;
}

unsigned int StatusManager::GetDefensePower()
{
    return this->defensePower;
}

unsigned int StatusManager::GetHp()
{
    return this->hp;
}

unsigned int StatusManager::GetMp()
{
    return this->mp;
}

unsigned int StatusManager::GetExe()
{
    return this->exe;
}

ElementType StatusManager::GetElementType()
{
    return this->element;
}

void StatusManager::SetElementType(ElementType element)
{
    this->element = element;
}

bool StatusManager::IsDead()
{
	return hp == 0;
}

void StatusManager::AddHp(unsigned int amount)
{
    hp += amount;
}

void StatusManager::SubHp(unsigned int amount)
{
    if (amount >= hp)
        hp = 0;
    else
        hp -= amount;
}

void StatusManager::AddMp(unsigned int amount)
{
    mp += amount;
}

void StatusManager::SubMp(unsigned int amount)
{
    if (amount >= mp)
        mp = 0;
    else
        mp -= amount;
}

void StatusManager::AddAttackPower(unsigned int attackPower)
{
    this->attackPower += attackPower;
}

void StatusManager::SubAttackPower(unsigned int attackPower)
{
    if (attackPower >= this->attackPower)
        this->attackPower = 0;
    else
        this->attackPower -= attackPower;
}

void StatusManager::AddDefensePower(unsigned int defensePower)
{
    this->defensePower += defensePower;
}

void StatusManager::SubDefensePower(unsigned int defensePower)
{
    if (defensePower >= this->defensePower)
        this->defensePower = 0;
    else
        this->defensePower -= defensePower;
}

void StatusManager::AddExe(unsigned int exe)
{
    this->exe += exe;
}

void StatusManager::SubExe(unsigned int exe)
{
    this->exe -= exe;
}
