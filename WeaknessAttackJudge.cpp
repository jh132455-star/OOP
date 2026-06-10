#include "WeaknessAttackJudge.h"

bool WeaknessAttackJudge::Judge(ElementType attacker, ElementType defender)
{
    if (attacker == ElementType::Fire && defender == ElementType::Grass) return true;
    if (attacker == ElementType::Water && defender == ElementType::Fire)  return true;
    if (attacker == ElementType::Grass && defender == ElementType::Earth) return true;
    if (attacker == ElementType::Earth && defender == ElementType::Water) return true;

    return false;
}