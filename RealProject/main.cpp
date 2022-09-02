﻿#include "Product.h"
#include "ShopInfo.h"
#include "ClientManager.h"
#include"ProductManager.h"
#include "ShopInfoManager.cpp"

void showMenu();
void showInfo();
void showShopInfo();
int cinmenu();
int cpmenu();

int main()
{
	int menu=0;	// 1. 고객 정보 관리 p2. 상품 정보 관리 3. 쇼핑 정보 관리
	int back;
	int Client_menu;
	int product_menu;
	int shoping_menu;

	ClientManager CM;
	ProductManager PM;
	ShopInfoManager SM;

	while (1) {

		showMenu();
		//cin >> menu;

		menu = cinmenu();
		switch (menu)
		{
		case 1:		//고객 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                         고객 관리 프로그램                         " << endl;
			showInfo();

			//cin >> Client_menu;
			Client_menu = cpmenu();
			switch (Client_menu)
			{
			case 0:	//메인화면으로
				break;
			case 1:		//입력
				CM.add_Client();
				break;
			case 2:		//조회
				CM.client_print();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
			case 3:		//검색
				CM.search_client();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 4:		//삭제
				CM.delete_client();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 5:		//변경
				CM.update_client();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			}	//고객 관리 프로그램 switch case문 종료

			break;	//case 1 break;

		case 2:		//제품 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                         제품 관리 프로그램                         " << endl;
			showInfo();
			//cin >> product_menu;
			product_menu = cpmenu();
			switch (product_menu)
			{
			case 0:	//메인화면으로
				break;
			case 1:		//입력
				PM.add_Product();
				break;
			case 2:		//조회
				PM.Product_print();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 3:		//검색
				PM.search_Product();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 4:		//삭제
				PM.delete_Product();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 5:		//변경
				PM.update_product();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			}
			break;

		case 3:		//쇼핑 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                         주문 프로그램                         " << endl;
			showShopInfo();
			cin >> shoping_menu;
			switch (shoping_menu)
			{
			case 1:		// 주문
				SM.add_Shoplist(CM.getClientList(), PM.getproductList());
				break;
			case 2:		//주문 현황 조회
				SM.shoplist_print(CM.getClientList(), PM.getproductList());
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
			}
			break;

		case 4:		// 종료
			exit(0);
			break;
		}
	}	//while 종료
	return 0;
}

void showMenu()
{
	system("cls"); 
	cout << LINE << endl;
	cout << "──────────────────────────────────고객 / 제품 관리 프로그램───────────────────────────────" << endl;
	cout << LINE << endl;
	cout << "1. 고객 정보 관리" << " / " << "2. 제품 정보 관리" << " / " << "3. 쇼핑 정보 관리" << " / " << "4. 프로그램 종료" << endl;
	cout << LINE << endl;
	cout << "                        몇번을 입력 하시겠습니까 ?                       " << endl;
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
	cout << "   1. 주문  /   2. 주문내역조회   /     " << endl;
	cout << LINE << endl;
}

int cinmenu()
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
}

int cpmenu()
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu >= 0 && menu < 6)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
}