// TownUi.cpp
#include "TownUi.h"

void TownUi::ShowMenu() {
    cout << "\n=== 마을 ===" << endl;
    cout << "0. 직업 변경" << endl;
    cout << "1. 체력 50 회복" << endl;
    cout << "2. 던전으로" << endl;
    cout << "3. 메인화면으로" << endl;
    cout << "Select: ";
}

UIType TownUi::GetType() {
    return UIType::Town;
}