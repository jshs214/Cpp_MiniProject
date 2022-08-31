#include "Client.h"
#include "Product.h"
#include <vector>
#include <algorithm>
#include <windows.h>	//콘솔 지우기 위한 헤더
#include "ClientManager.cpp"
#include "ProductManager.cpp"

void showMenu();
void search_client();
int main()
{
	int menu;
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

			cout << "1. 입력 / 2. 조회 / 3. 검색 / 4. 삭제 / 5. 변경" << endl;

			cin >> customer_menu;
			switch (customer_menu) 
			{
			case 1:		//입력
				CM.add_Client();
				break;
			case 2:		//조회
				CM.add_client_print();
				break;
			case 3:		//검색
				CM.search_client();
				break;
			case 4:		//삭제
				CM.delete_client();
				break;
			case 5:		//변경
				
				break;
			}
			
			break;

		case 2:		//상품 정보 관리
			system("cls");
			
			cout << "1. 입력 / 2. 조회 / 3. 검색 / 4. 삭제 / 5. 변경" << endl;
			cin >> product_menu;
			switch (product_menu)
			{
			case 1:		//입력
				PM.add_Product();
				break;
			case 2:		//조회
				PM.add_Product_print();
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
		}

	}



	return 0;
}
void showMenu() 
{
	cout << "========================================================================" << endl;
	cout << "                           상품 관리 프로그램                         " << endl;
	cout << "                           1. 고객 정보 관리                         " << endl;
	cout << "                           2. 상품 정보 관리                         " << endl;
	cout << "                           3. 쇼핑 정보 관리                         " << endl;
	cout << "                        몇번을 입력 하시겠습니까 ?                       " << endl;
	cout << "========================================================================" << endl;
}
