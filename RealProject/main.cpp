#include "ClientManager.h"
#include"ProductManager.h"
#include "ShopInfoManager.h"

#include<iostream>

void showMenu();
void showInfo();
void showShopInfo();

int inmenu();	// 메인에서 정해진 범위만 받도록


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
		case 1:		//고객 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            고객 관리 프로그램" << endl;
			showInfo();
			CM.ClientMainMenu();
			break;	//case 1 break;
		case 2:		//제품 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            제품 관리 프로그램" << endl;
			showInfo();
			PM.ProductMainMenu();
			break;
		case 3:		//쇼핑 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                                            주문 프로그램" << endl;
			showShopInfo();
			SM.ShopMainMenu();
			break;
		case 4:		// 종료
			whileflag = true;
			break;
		}
		if (whileflag == true)	break;	// while 종료조건
	}	//while 종료

	cout << "[프로그램이 정상 종료 되었습니다.]" << endl;
	return 0;
}

void showMenu()
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

void showInfo()
{
	cout << LINE << endl;
	cout << "   1.입력   /   2. 조회   /   3. 검색   /   4. 삭제   /   5. 변경   / (메인화면가기 0)" << endl;
	cout << LINE << endl;
}
void showShopInfo()
{
	cout << LINE << endl;
	cout << "   1. 주문  /   2. 주문내역조회   /   3. 주문내역검색   /   4. 주문정보 변경   /   5. 주문내역삭제" << endl;
	cout << LINE << endl;
}

int inmenu() //메인에서 정해진 범위만 받도록
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