#include "BattleUi.h"

void BattleUi::ShowMenu()
{
	std::cout << "\n=== 교전 중 수행할 동작을 선택하세요 ===" << std::endl;
	std::cout << "1. 일반 공격" << std::endl;
	std::cout << "2. 스킬공격" << std::endl;
	std::cout << "3. 도망가기" << std::endl;
	std::cout << "선택: " <<endl;
}

UIType BattleUi::GetType()
{
	return UIType::Battle;
}
