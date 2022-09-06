#include "ProductManager.h"
#include<vector>
#include <algorithm>
#include<fstream>
#include<string>
#include<sstream>

ProductManager::ProductManager()		//ProductManager 생성자에서 파일 load
{
	ifstream file;
	file.open("Product.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int price = atoi(row[2].c_str());
				int stock = atoi(row[4].c_str());

				Product* p = new Product(row[0], row[1], price, row[3],stock);
				productList.push_back(p);
			}
		}
	}
	file.close();
}

ProductManager::~ProductManager()		//ProductManager 소멸자에서 파일 입력
{
	ofstream fs("Product.txt");
	if (!fs) {
		cout << "출력할 파일을 열 수 없습니다.";
		Sleep(1000);
	}

	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		fs << (*it)->getProductID() << ", "
			<< (*it)->getProductName() << ", "
			<< (*it)->getPrice() << ", "
			<< (*it)->getProductType() << ", "
			<< (*it)->getStock()<<endl;
	}
	fs.close();
}

vector<Product*>& ProductManager::getproductList()
{
	return productList;
}

void ProductManager::ProductMainMenu()
{
	int back = 0;
	int product_menu;
	product_menu = cpmenu();	//제품관리메뉴에서 정해진 범위만 받도록

	switch (product_menu)
	{
	case 0:	//메인화면으로
		break;
	case 1:		//입력
		add_Product();
		break;
	case 2:		//조회
		Product_print();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	case 3:		//검색
		search_Product();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	case 4:		//삭제
		delete_Product();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	case 5:		//변경
		update_product();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	}
}
void ProductManager::add_Product()		// 제품 추가
{
	string productID, productName, productType;	// 입력할 제품코드, 제품명, 제품종류
	int price = 0, stock=0;			// 가격, 재고수량

	system("cls");
	cout << LINE << endl;
	cout << "                                            신규 제품 등록" << endl;
	cout << LINE << endl;

	cout << "제품코드 (PK) : "; cin >> productID;
	cout << "제품명 : "; cin >> productName;
	while (1) {		// 가격 입력칸에 숫자만 들어가는지 검사
		cout << "가격 : "; cin >> price;
		if (!cin) {		// cin menu 에 숫자만 입력 받도록
			cout << "[숫자만 입력해주세요]"<<endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else break;
	}
	cout << "종류 : "; cin >> productType;
	cout << "재고 : "; cin >> stock;

	while (1) {	// PK(제품ID) 중복검사
		bool flag = false;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_PK = (*it)->getProductID();
			if (sch_PK == productID) {
				flag = true;
				break;
			}
		}
		if (flag == false)	break;
		else
		{
			cout << " 중복되는 제품 ID 입니다. 다시 입력해 주세요 (종료 0): ";
			cin >> productID;
			if (productID == "0")return;	//종료조건
		}
	}

	Product* newProduct = new Product(productID, productName, price, productType,stock);
	productList.push_back(newProduct);

	cout << "[제품 등록 완료]" << endl;

	Sleep(1000);	//Delay 1초
}

void ProductManager::Product_print()		// 조회
{
	system("cls");

	cout << LINE << endl;
	cout << "                                            제품정보조회" << endl;
	cout << LINE << endl;
	cout << "    제품코드 (PK)     /   제품명   /   가격     /    종류   /   재고" << endl;
	cout << LINE << endl;

	sort(productList.begin(), productList.end(), [](Product* a, Product* b) {		//제품ID 기준으로 정렬
		return a->getProductID() < b->getProductID();
		});

	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		showProductlist(*it);
	}

	cout << "[제품정보 조회 완료]" << endl;
	cout << LINE << endl;
	cout << "[총 " << productList.size() << "건의 제품정보가 있습니다]" << endl;
	cout << LINE << endl;
}


void ProductManager::search_Product()		// 검색
{
	string input;	//검색 시 데이터와 매칭하기 위해 입력받는 지역변수
	int num = 0;		//무엇을 검색할지 switch case
	bool flag = 0;

	system("cls");
	cout << LINE << endl;
	cout << "                                            제품 검색" << endl;
	cout << LINE << endl;
	cout << "1. 제품명 검색 2. 종류 검색 "; //cin >> num;

	num = psearach_menu();
	switch (num)
	{
	case 1:
		cout << "제품명 검색 : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                                       [입력한 제품명 : " << input << " 검색결과]" << endl;
		cout << LINE << endl;
		cout << "      제품코드(PK)     /   제품명    /    가격    /    종류" << endl;
		cout << LINE << endl;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_name = (*it)->getProductName();
			if (sch_name.find(input) != -1) {
				flag = true;
				showProductlist(*it);
			}
		}
		if (flag == false)
			cout << "[입력하신 제품명이 없습니다]" << endl;
		cout << LINE << endl;
		break;		// case 1 break;

	case 2:
		cout << "종류 검색 : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                                       [입력한 제품종류 : " << input << " 검색결과]" << endl;
		cout << LINE << endl;
		cout << "      제품코드(PK)     /   제품명    /    가격    /    종류   /   재고" << endl;
		cout << LINE << endl;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_type = (*it)->getProductType();
			if (sch_type.find(input) != -1) {
				flag = true;
				showProductlist(*it);
			}
		}
		if (flag == false)
			cout << "[입력하신 제품의 종류가 없습니다]" << endl;
		cout << LINE << endl;
		break;		// case 2 break;
	}
}

void ProductManager::delete_Product()		//삭제
{
	string input;	//삭제 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수
	bool flag = false;
	system("cls");
	cout << LINE << endl;
	cout << "                                            제품 정보 삭제                              " << endl;
	cout << LINE << endl;
	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		showProductlist(*it);
	}
	cout << LINE << endl;
	cout << "삭제할 제품 ID 입력하세요 : "; cin >> input;

	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		auto sch_ID = (*it)->getProductID();
		if (sch_ID == input) {
			flag = true;
			productList.erase(it);
			cout << input << " 에 대한 정보가 삭제되었습니다." << endl;
			cout << "[제품정보 삭제 완료]" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "[입력하신 제품 ID가 없습니다]" << endl;
	cout << LINE << endl;
}

void ProductManager::update_product()	//정보 변경
{
	string input;	//정보 변경 시 입력받는 제품 ID 변수
	bool flag = false;
	int data;		//업데이트 시 변경할 데이터

	system("cls");
	cout << LINE << endl;
	cout << "                                            제품 정보 변경" << endl;
	cout << LINE << endl;
	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		showProductlist(*it);
	}
	cout << LINE << endl;
	cout << "변경할 제품 코드 입력 : "; cin >> input;

	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		auto sch_name = (*it)->getProductID();		//입력한 제품 ID 데이터가 있으면

		if (sch_name == input) {
			flag = true;
			cout << "1. 가격 변경  2. 재고 변경 " << endl;		//cin >> num;	//변경할 정보
			int num = pupdate_menu();
			switch (num)
			{
			case 1:		//가격 변경
				cout << "변경할 가격 입력" << endl;
				data=update_data();
				if (data != 0) {
					(*it)->setPrice(data);
					cout << "[가격 변경 완료]" << endl;
				}
				else if (data == 0) {
					(*it)->setPrice(data);
					cout << "[가격 변경 완료]" << endl;
				}
				break;

			case 2:		//재고 변경
				cout << "변경할 재고 수량 입력" << endl;
				data = update_data();
				if (data != 0) {
					(*it)->setStock(data);
					cout << "[재고 변경 완료]" << endl;
				}
				else if (data == 0) {
					(*it)->setStock(data);
					cout << "[재고 변경 완료]" << endl;
				}
				break;
			}
		}
	}
		if (flag == false)
			cout << "[입력하신 제품 코드가 없습니다]" << endl;

		cout << LINE << endl;
	
}//정보 변경 함수 종료
void ProductManager::showProductlist(Product* productinfo)		//clientList 출력
{
	cout << "(PK)" << productinfo->getProductID() << "-> "
		<< productinfo->getProductName() << " / "
		<< productinfo->getPrice() << " / "
		<< productinfo->getProductType() << " / "
		<< productinfo->getStock() << "개" << endl;
}

int ProductManager::cpmenu()	// 고객,제품 관리 메뉴에서 정해진 범위만 받도록
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
	return 0;
}

int ProductManager::psearach_menu()		// 검색 메뉴 입력 예외처리
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 3)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

int ProductManager::pupdate_menu()	// 변경 메뉴 입력 예외 처리
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 3)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}
int ProductManager::update_data() // 예외 처리
{
	int data;
	cin >> data;
	if (!cin) {		// cin 에 숫자만 입력 받도록
		cout << "[범위가 벗어났습니다. 999999999 이하의 양수만 입력해주세요]";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (data >= 0 && data < 999999999)
		return data;
	else {
		cout << "[범위가 벗어났습니다. 999999999 이하의 양수만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

vector<string> ProductManager::parseCSV(istream& file, char delimiter)
{
	stringstream ss;
	vector<string> row;
	string t = " \n\r\t";

	while (!file.eof()) {
		char c = file.get();
		if (c == delimiter || c == '\r' || c == '\n') {
			if (file.peek() == '\n') file.get();
			string s = ss.str();
			s.erase(0, s.find_first_not_of(t));
			s.erase(s.find_last_not_of(t) + 1);
			row.push_back(s);
			ss.str("");
			if (c != delimiter) break;
		}
		else {
			ss << c;
		}
	}
	return row;
}