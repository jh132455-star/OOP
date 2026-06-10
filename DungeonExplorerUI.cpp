#include "DungeonExplorerUI.h"

void DungeonExplorerUI::ShowMenu()
{
	std::cout << "\n=== 던전에서 수행할 동작을 선택하세요 ===" << std::endl;
	std::cout << "1. 던전 탐색" << std::endl;
	std::cout << "2. 마을로 돌아가기" << std::endl;
	std::cout << "3. 메인으로 돌아가기" << std::endl;
	std::cout << "선택: ";
}

UIType DungeonExplorerUI::GetType()
{
	return UIType::DungeonExplorer;
}
