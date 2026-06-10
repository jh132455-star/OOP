#include "Warrior.h"


unsigned int Warrior::UseSkill(unsigned int& currentMp)
{
    unsigned int needMp = 10;
    unsigned int damage = 100;

    if (currentMp >= needMp)
        return damage;
    return 0;
}