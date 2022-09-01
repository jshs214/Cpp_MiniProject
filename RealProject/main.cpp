#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"
#include <vector>
#include <algorithm>
#include <windows.h>	//콘솔 지우기 위한 헤더
#include "ClientManager.cpp"
#include "ProductManager.cpp"
#include "ShopInfoManager.cpp"

void showMenu();
void showInfo();
void showShopInfo();
int main()
{
	int menu;	// 1. 고객 정보 관리 2. 상품 정보 관리 3. 쇼핑 정보 관리
	int back;
	int customer_menu;
	int product_menu;
	int shoping_menu;
	ClientManager CM;
	ProductManager PM;
	ShopInfoManager SM;
	while (1) {
		//system("cls");
		showMenu();
		cin >> menu;
		switch (menu)
		{
		case 1:		//고객 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                         고객 관리 프로그램                         " << endl;
			showInfo();

			cin >> customer_menu;
			switch (customer_menu) 
			{
			case 1:		//입력
				CM.add_Client();
				break;
			case 2:		//조회
				CM.client_print();
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

		case 2:		//제품 정보 관리
			system("cls");
			cout << LINE << endl;
			cout << "                         제품 관리 프로그램                         " << endl;
			showInfo();
			cin >> product_menu;
			switch (product_menu)
			{
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
			case 3:		//검색
				CM.search_client();
				cout << "종료 (0) "; cin >> back;
				if (back == 0)break;
				break;
			}
			
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
	cout << "                         고객 / 제품 관리 프로그램                         " << endl;
	cout << LINE << endl;
	cout << "1. 고객 정보 관리" << " / " << "2. 제품 정보 관리" << " / " << "3. 쇼핑 정보 관리" << " / " << "4. 프로그램 종료" << endl;
	cout << LINE << endl;
	cout << "                        몇번을 입력 하시겠습니까 ?                       " << endl;
	cout << LINE << endl;
}

void showInfo()
{
	cout << LINE << endl;
	cout << "   1.입력   /   2. 조회   /   3. 검색   /   4. 삭제   /   5. 변경   " << endl;
	cout << LINE << endl;
}
void showShopInfo()
{
	cout << LINE << endl;
	cout << "   1. 주문  /   2. 주문내역조회   /     " << endl;
	cout << LINE << endl;
}