#include "MainUi.h"

void MainUi::ShowMenu()
{
	cout << "=== 원하는 동작을 선택하세요 ===" << endl;
	cout << "0. 캐릭터 생성" << endl;
	cout << "1. 마을 입장" << endl;
	cout << "2. 던전 입장" << endl;
	cout << "3. 종료" << endl;
	cout << "선택: ";
}

UIType MainUi::GetType()
{
	return UIType::Main;
}
