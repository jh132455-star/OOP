#include "DungeonSelectUi.h"

void DungeonSelectUi::ShowMenu()
{
	std::cout << "\n=== 입장을 원하는 던전을 선택하세요 ===" << std::endl;
	std::cout << "1. 슬라임 던전" << std::endl;
	std::cout << "2. 고블린 던전" << std::endl;
	std::cout << "3. 드래곤 던전" << std::endl;
	std::cout << "4. 마을로 돌아가기" << std::endl;
	std::cout << "5. 메인으로 돌아가기" << std::endl;
	std::cout << "선택: ";
}

UIType DungeonSelectUi::GetType()
{
	return UIType::DungeonSelect;
}
