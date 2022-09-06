#include "ClientManager.h"
#include"ProductManager.h"
#include "ShopInfoManager.h"

#include<iostream>

void showMenu();	//디자인을위한 메뉴 출력 함수 
void showInfo();	//디자인을 위한 메뉴 선택창 함수
void showShopInfo(); //ShopInfo 디자인을 위한 함수

int inmenu();	// 1 ~ 4 정해진 입력 범위만 받도록


int main()
{
	int menu=0;	// 1. 고객 정보 관리 p2. 상품 정보 관리 3. 쇼핑 정보 관리

	bool whileflag = false;

	ClientManager CM;
	ProductManager PM;
	ShopInfoManager SM(CM,PM);

	while (1) {
		showMenu();
		menu = inmenu();
		switch (menu)
		{
		case 1:		//고객정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            고객 관리 프로그램" << endl;
			showInfo();		//디자인을 위한 메뉴 선택창 함수
			CM.ClientMainMenu();	//고객관리 동작함수 
			break;
		case 2:		//제품정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            제품 관리 프로그램" << endl;
			showInfo();		//디자인을 위한 메뉴 선택창 함수
			PM.ProductMainMenu();	//제품관리 동작함수
			break;
		case 3:		//주문정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            주문 프로그램" << endl;
			showShopInfo();		//디자인을 위한 메뉴 선택창 함수
			SM.ShopMainMenu();	//주문정보관리 동작함수
			break;
		case 4:		// 종료
			whileflag = true;	// 정상종료 조건
			break;
		}
		if (whileflag == true)	break;	// while 종료조건
	}	//while 종료

	cout << "[프로그램이 정상 종료 되었습니다.]" << endl;
	return 0;
}

void showMenu()		// 디자인을위한 메뉴 출력 함수
{
	system("cls"); 
	cout << LINE << endl;
	cout << "                                            고객 / 제품 관리 프로그램                              " << endl;
	cout << LINE << endl;
	cout << "1. 고객 정보 관리" << "   /   " << "2. 제품 정보 관리" << "   /   " << "3. 쇼핑 정보 관리" << "   /   " << "4. 프로그램 저장 및 종료" << endl;
	cout << LINE << endl;
	cout << "                                            몇번을 입력 하시겠습니까 ?                       " << endl;
	cout << LINE << endl;
}

void showInfo()		// 디자인을 위한 1 ~ 5 메뉴선택 함수
{
	cout << LINE << endl;
	cout << "   1.입력   /   2. 조회   /   3. 검색   /   4. 삭제   /   5. 변경   / (메인화면가기 0)" << endl;
	cout << LINE << endl;
}
void showShopInfo()		//ShopInfo 디자인을 위한 함수
{
	cout << LINE << endl;
	cout << "   1. 주문  /   2. 주문내역조회   /   3. 주문내역검색   /   4. 주문정보 변경   /   5. 주문내역삭제" << endl;
	cout << LINE << endl;
}

int inmenu() //1 ~ 4 정해진 입력 범위만 받도록
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 5)
		return menu;
	else {
	cout << "[메뉴 번호만 입력해주세요]" << endl;
	Sleep(1000);
	}
	return 0;
}