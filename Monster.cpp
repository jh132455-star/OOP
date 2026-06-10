#include "Monster.h"

Monster::Monster()
    : statusManager(100, 50, 10, 5, 0)  // hp, mp, attackPower, defensePower
{
    statusManager.SetElementType(ElementType::Grass);
}

Monster::Monster(StatusManager status, ElementType element)
{
    this->statusManager = status;
    this->statusManager.SetElementType(element);
}

void Monster::SetDropList(std::map<ItemType, size_t> dropList)
{
    this->dropList = dropList;
}

unsigned int Monster::Attack()
{
    unsigned int damage = statusManager.GetAttackPower();
    std::cout << "Monster Attack" <<std::endl;
    return damage;
}

void Monster::TakeDamage(unsigned int damage)
{
    unsigned int defense = statusManager.GetDefensePower();

    if (damage == 0)
    {
        std::cout << "Character Defense" << std::endl;
        return;
    }
    else 
    {
        statusManager.SubHp(damage - defense);

        std::cout << "Monster Take Damage :: damage = " << damage << std::endl;
        std::cout << "Monster's remain Hp = " << statusManager.GetHp() << std::endl;
    }

}

bool Monster::IsDead()
{
    return statusManager.IsDead();
}

ElementType Monster::GetElementType()
{
    return statusManager.GetElementType();
}

unsigned int Monster::GetDefensePower()
{
    return statusManager.GetDefensePower();
}

unsigned int Monster::GetExe()
{
    return statusManager.GetExe();
}

std::map<ItemType, size_t> Monster::GetDropList()
{
    return dropList;
}
