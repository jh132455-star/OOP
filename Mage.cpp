#include "Mage.h"

unsigned int Mage::UseSkill(unsigned int& currentMp)
{
    unsigned int needMp = 20;
    unsigned int damage = 200;

    if (currentMp >= needMp)
        return damage;
    return 0;
}
