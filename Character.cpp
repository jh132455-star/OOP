#include "Character.h"

Character::Character()
    : statusManager(100, 50, 10, 5, 0)  // hp, mp, attackPower, defensePower
{
    statusManager.SetElementType(ElementType::Fire);
}

Character::Character(unsigned int hp, unsigned int mp, unsigned int attackPower, unsigned int defensePower)
    : statusManager(hp, mp, attackPower, defensePower, 0)
{
    statusManager.SetElementType(ElementType::Fire);
}

unsigned int Character::Attack()
{
    unsigned int damage = statusManager.GetAttackPower();
    std::cout << "Character Attack" << std::endl;

    return damage;
}

void Character::TakeDamage(unsigned int damage)
{
    if (damage == 0)
    {
        std::cout << "Character Defense" << std::endl;
        return;
    }
    else 
    {
        statusManager.SubHp(damage);

        std::cout << "Character Take Damage :: damage = " << damage << std::endl;
        std::cout << "Character's remain Hp = " << statusManager.GetHp() << std::endl;
    }
}

void Character::TakeHp(unsigned int amount)
{
    statusManager.AddHp(amount);
}

void Character::EquipWeapon(Weapon* weapon)
{
    equipmentManager.EquipWeapon(weapon);
}

void Character::EquipArmor(Armor* armor)
{
    equipmentManager.EquipArmor(armor);
}

void Character::UnequipWeapon()
{
    Weapon* weapon = equipmentManager.GetWeapon();
    if (equipmentManager.UnequipWeapon())
        statusManager.SubAttackPower(weapon->GetAttackBonus());
}

void Character::UnequipArmor()
{
    Armor* armor = equipmentManager.GetArmor();
    if (equipmentManager.UnequipWeapon())
        statusManager.SubDefensePower(armor->GetDefenseBonus());
}

void Character::AcquireItems(std::map<ItemType, size_t> itemList)
{
    for (auto& pair : itemList)
    {
        for (size_t i = 0; i < pair.second; i++)
        {
            inventory.InsertItem(pair.first);
        }
    }
}

void Character::AcquireExe(unsigned int exe)
{
    statusManager.AddExe(exe);
}

unsigned int Character::GetBonusAttackPower()
{
    return equipmentManager.GetBonusAttackPower();
}
unsigned int Character::GetBonusDefensePower()
{
    return equipmentManager.GetBonusDefensePower();
}

unsigned int Character::GetExe()
{
    return statusManager.GetExe();
}


bool Character::IsDead()
{   
    return statusManager.IsDead();
}

bool Character::HasJob()
{
    return this->job != nullptr;
}

ElementType Character::GetElementType()
{
    return statusManager.GetElementType();
}

unsigned int Character::GetDefensePower()
{
    return statusManager.GetDefensePower();
}

unsigned int Character::GetMp()
{
    return statusManager.GetMp();
}

Job* Character::GetJob()
{
    return this->job.get();
}

bool Character::SetJob(std::unique_ptr<Job> job)
{
    this->job = std::move(job);
    return true;
}
