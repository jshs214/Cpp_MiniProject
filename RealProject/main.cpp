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
	int menu=0;	// 1 ~ 3 메뉴

	bool whileflag = false;

	ClientManager CM;		// 고객정보를 관리하는 객체
	ProductManager PM;		// 제품정보를 관리하는 객체
	ShopInfoManager SM(CM,PM);	// 주문정보를 관리하는 객체

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
		case 4:	
			whileflag = true;	// 종료조건
			break;
		}
		if (whileflag == true)	break;
	}

	cout << "[프로그램이 정상 종료 되었습니다.]" << endl;
	return 0;
}

/**
*  디자인을위한 디자인메뉴출력 함수
*/
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

/**
*  디자인을 위한 1 ~ 5 메뉴선택 출력함수
*/
void showInfo()	
{
	cout << LINE << endl;
	cout << "   1.입력   /   2. 조회   /   3. 검색   /   4. 삭제   /   5. 변경   / (메인화면가기 0)" << endl;
	cout << LINE << endl;
}

/**
* ShopInfo 디자인을 위한 출력함수
*/
void showShopInfo()
{
	cout << LINE << endl;
	cout << "   1. 주문  /   2. 주문내역조회   /   3. 주문내역검색   /   4. 주문정보 변경   /   5. 주문내역삭제" << endl;
	cout << LINE << endl;
}


/**
* 입력값 예외처리 함수
* @ exception 정해진 입력값이 아닐 경우 예외처리
* @ return 입력값 반환
*/
int inmenu()
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin에 숫자만 입력 받도록
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