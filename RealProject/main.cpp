#include "Client.h"
#include "Product.h"
#include <vector>
#include <algorithm>
#include <windows.h>	//콘솔 지우기 위한 헤더
#include "ClientManager.cpp"
#include "ProductManager.cpp"

void showMenu();
void showInfo();
int main()
{
	int menu;	// 1. 고객 정보 관리 2. 상품 정보 관리 3. 쇼핑 정보 관리
	int back = 0;
	int customer_menu;
	int product_menu;

	ClientManager CM;
	ProductManager PM;

	while (1) {
		//system("cls");
		showMenu();
		cin >> menu;
		switch (menu)
		{
		case 1:		//고객 정보 관리
			system("cls");

			showInfo();

			cin >> customer_menu;
			switch (customer_menu) 
			{
			case 1:		//입력
				CM.add_Client();
				break;
			case 2:		//조회
				CM.add_client_print();
				cout << "종료 (0) "; cin >> back;
				if(back==0)break;
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
			}
			
			break;

		case 2:		//상품 정보 관리
			system("cls");
			
			showInfo();
			cin >> product_menu;
			switch (product_menu)
			{
			case 1:		//입력
				PM.add_Product();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 2:		//조회
				PM.add_Product_print();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			case 3:		//검색
				break;
			case 4:		//삭제
				break;
			case 5:		//변경
				break;
			}
			break;

		case 3:		//쇼핑 정보 관리

			break;

		case 4:		// 종료
			exit(0);
			break;
		}

	}



	return 0;
}

void showMenu()
{
	system("cls"); 
	cout << LINE << endl;
	cout << "                           상품 관리 프로그램                         " << endl;
	cout << "                           1. 고객 정보 관리                         " << endl;
	cout << "                           2. 상품 정보 관리                         " << endl;
	cout << "                           3. 쇼핑 정보 관리                         " << endl;
	cout << "                           4. 프로그램 종료                         " << endl;
	cout << "                        몇번을 입력 하시겠습니까 ?                       " << endl;
	cout << LINE << endl;
}

void showInfo()
{
	cout << LINE << endl;
	cout << "                           1. 입력                         " << endl;
	cout << "                           2. 조회                         " << endl;
	cout << "                           3. 검색                         " << endl;
	cout << "                           4. 삭제                         " << endl;
	cout << "                           5. 변경                         " << endl;
	cout << LINE << endl;
}