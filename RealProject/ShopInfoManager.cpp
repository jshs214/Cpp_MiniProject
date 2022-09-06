#include "ShopInfoManager.h"

#include <vector>
#include <algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include <iomanip>


ShopInfoManager::ShopInfoManager(ClientManager& cm,ProductManager& pm)
	:CM(cm), PM(pm)
{
	ifstream file;
	file.open("ShopInfo.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int shopkey = atoi(row[0].c_str());		// int형 ShopInfo의 PK키 형변환
				int price = atoi(row[4].c_str());		// int형 가격 형변환
				int stock = atoi(row[5].c_str());		// int형 수량 형변환
				ShopInfo* s = new ShopInfo(shopkey, row[1], row[2], row[3], price, stock, row[6], row[7], row[8], row[9]);
				ShopInfolist.push_back(s);
			}
		}
	}
	file.close();
}

ShopInfoManager::~ShopInfoManager()
{
	ofstream fs("ShopInfo.txt");
	if (!fs) {
		cout << "출력할 파일을 열 수 없습니다.";
		Sleep(1000);
	}

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
	{
		fs << (*it)->getShopkey() << ", " << (*it)->getProductID() << ", " << (*it)->getproductName() << ", " 
			<< (*it)->getproductType() << ", " << (*it)->getPrice() << ", " << (*it)->getStock() << ", "
			<< (*it)->getname() << ", " << (*it)->getclientID() << ", " << (*it)->getphoneNumber() << ", "
			<<(*it)->getaddress() << ", "<<endl;
	}
	fs.close();
}

void ShopInfoManager::ShopMainMenu()
{
	int shoping_menu;
	int back = 0;
	shoping_menu = smenu();	//쇼핑정보메뉴에서 정해진 범위만 받도록
	switch (shoping_menu)
	{
	case 1:		// 주문
		add_Shoplist();
		break;
	case 2:		//주문 내역 조회
		shoplist_print();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	case 3:		//주문 내역 검색
		search_shoplist();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	}
}
void ShopInfoManager::add_Shoplist()       // 주문하기
{
	int shopkey=1000, stock = 0,price =0;	//ShopInfo의 PK키 1000부터 시작 , 주문 할 수량, 가격
	string cid, pid;	// 입력받을 ClientID와 ProductID 변수
	int up_stock;	// 재고반영에 필요한 변수
	int cinput = 0, pinput=0, sinput=0; //일치하는지 flag

	string productid, productname, producttype, name, clientid, phonenumber, address;

	bool cflag = false, pflag=false;	//경계검사를위한 변수
	
	system("cls");
	cout << LINE << endl;
	cout << "                                            주문                             " << endl;
	cout << LINE << endl;


	cout << "고객 ID : "; cin >> cid;   // ClientID PK검사를 위한 cin
	cout << "제품 ID : "; cin >> pid;   // ProductID PK검사를 위한 pin
	cout << "구매할 제품 개수 : "; cin >> stock;

	while (1) {					//Client ID 중복검사 ( 같아야 진행 )
		cflag = false;
		cinput = 0;// ClientID가 정상적으로 생성되면 1, 아니면 0
		for (auto it =CM.getClientList().begin(); it != CM.getClientList().end(); ++it)
		{
			auto sch_cid = (*it)->getclientID();
			if (sch_cid == cid) {           // ClientID와 입력한 id가 같으면
				cflag = true;
				cinput++;
				break;
			}
		}
		if (cflag == true)	break;
		else
		{
			cout << "고객 ID가 없습니다. 재입력 해주세요 (종료 0) : ";
			cin >> cid;
		}

		if (cid == "0")    return;		//종료조건
	}

	while (1) {					//Product ID 중복검사 ( 같아야 진행 )
		pflag = false;
		pinput = 0;	// ProductID가 정상적으로 생성되면 1, 아니면 0
		for (auto it = PM.getproductList().begin(); it != PM.getproductList().end(); ++it)
		{
			auto sch_pid = (*it)->getProductID();
			if (sch_pid == pid) {           // ClientID와 입력한 id가 같으면
				pflag = true;
				pinput++;
				break;
			}
		}
		if (pflag == true)	break;
		else
		{
			cout << "제품 ID가 없습니다. 재입력 해주세요 (종료 0) :";
			cin >> pid;
		}
		if (pid == "0") return;		//종료조건
		}

		for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)		// Client의 데이터를 ShopInfolist 벡터에 값복사
		{
			auto sch_cid = (*cit)->getclientID();
			if (sch_cid == cid) {           
				name = (*cit)->getName();
				clientid = (*cit)->getclientID();
				phonenumber = (*cit)->getPhoneNumber();
				address = (*cit)->getAddress();
			}
		}

		for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)		// Product의 데이터를 ShopInfolist 벡터에 값복사
		{
			auto sch_PK = (*pit)->getProductID();
			if (sch_PK == pid) {
				productid = (*pit)->getProductID();
				productname = (*pit)->getProductName();
				price = (*pit)->getPrice();
				producttype = (*pit)->getProductType();
			}
		}
	

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //주문내역 PK 중복검사
	{
		auto sch_shopkey = (*it)->getShopkey();
		if (sch_shopkey == shopkey) {
			shopkey++;
		}
	}
	
	for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {				// 주문 할 때 Product의 재고가 빠지는 동작
		auto id = (*pit)->getProductID();	////Product에 있는 고객ID
		if (pid == id) {			//pid는 주문 할 때 입력한 고객 id
			while (1) {
				sinput = 0;// 주문수량보다 재고가 많으면 1, 아니면 0

				if (((*pit)->getStock() - stock) < 0) {
					cout << "[주문 수량이 재고보다 많습니다. " << (*pit)->getStock() << "개 남았습니다.]" << endl;
					cout << "주문 수량을 재입력 해주세요 (종료 0) :";
					cin >> stock;
					if (stock == 0)	break;
				}
				else {
					sinput++;
					up_stock = (*pit)->getStock() - stock;
					(*pit)->setStock(up_stock);
					cout << "[주문 완료]" << endl;
					break;
				}
			}
		}
	}
	
	if (cinput > 0 && pinput > 0&& sinput > 0) {			// Client, Product가 정상적으로 생성되고, 재고가 정상적이면 주문리스트 추가
		ShopInfo* newShopC = new ShopInfo(shopkey, productid, productname, producttype, price, stock, name, clientid, phonenumber, address);
		ShopInfolist.push_back(newShopC);
	}
	Sleep(1000);	//Delay 1초
}//void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // 주문하기 함수 종료


void ShopInfoManager::shoplist_print()     // 조회
{
	int sum = 0;   //총합

	system("cls");
	cout << LINE << endl;
	cout << "                                            제품정보조회                             " << endl;
	cout << LINE << endl;

	print_Shopmenu();		//주문내역 테이블 메뉴

	sort(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* a, ShopInfo* b) {		//주문번호 기준으로 정렬
		return a->getShopkey() < b->getShopkey();
		});

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 출력
	{
		sum = (*it)->getPrice() * (*it)->getStock();
		cout.setf(ios::left); //좌측 정렬 후 출력
		cout << " #" << setw(27) << (*it)->getShopkey() << setw(15) << (*it)->getProductID() << setw(15) << (*it)->getproductName() << setw(15)
			<< (*it)->getproductType() << setw(11) << (*it)->getPrice()
			<< setw(11) << (*it)->getStock() << setw(15) << sum << endl;
		cout << "  " << setw(27) << (*it)->getname() << setw(15) << (*it)->getclientID() << setw(15) << (*it)->getphoneNumber()
			<< (*it)->getaddress() << endl << endl;
	}

	cout << "[주문내역 조회 완료]" << endl;
	cout << LINE << endl;
	cout << "[총 " << ShopInfolist.size() << "건의 주문이 있습니다.]" << endl;
	cout << LINE << endl;
}//void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 조회하기 함수 종료

void ShopInfoManager::search_shoplist()    //검색
{
	string name, phonenumber, address, productname, producttype;            //Client 고객명, 전화번호, 주소, 제품명, 제품종류
	string input;	//검색 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수
	int price;           //  제품 가격
	int sum = 0;   //총합


	bool flag = false;
	int num = 0;	//어떤 조건을 검사할지 switch case 변수

	system("cls");
	cout << LINE << endl;
	cout << "                                            주문내역 검색                             " << endl;
	cout << LINE << endl;
	cout << "1. 고객 ID 검색 2. 제품코드 검색 ";

	num = ssearach_menu();		// 검색 메뉴 입력 예외처리

	switch (num) {
	case 1:
		cout << "검색할 고객 ID를 입력하세요 : ";
		cin >> input;
		
		system("cls");
		cout << LINE << endl;
		cout << "                                             고객 ID 검색결과                             " << endl;
		cout << LINE << endl;
		print_Shopmenu();		//주문내역 테이블 메뉴

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
		{
			if ((*it)->getclientID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if ((*cit)->getclientID().find(input) != -1) {// 클라이언트 ID와 입력한 input 문자열에 겹치는게 있으면
						flag = true;
						if (c_ID == (*cit)->getclientID()) {
							name = (*cit)->getName();
							phonenumber = (*cit)->getPhoneNumber();
							address = (*cit)->getAddress();
						}
					}
				}
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if (p_ID == (*pit)->getProductID()) {
						productname = (*pit)->getProductName();
						producttype = (*pit)->getProductType();
						price = (*pit)->getPrice();
						sum = price * (*it)->getStock();
					}
				}
				cout.setf(ios::left); //좌측 정렬 후 출력
				cout << " #" << setw(27) << (*it)->getShopkey() << setw(15) << (*it)->getProductID() << setw(15) << (*it)->getproductName() << setw(15)
					<< (*it)->getproductType() << setw(11) << (*it)->getPrice()
					<< setw(11) << (*it)->getStock() << setw(15) << sum << endl;
				cout << "  " << setw(27) << (*it)->getname() << setw(15) << (*it)->getclientID() << setw(15) << (*it)->getphoneNumber()
					<< (*it)->getaddress() << endl << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 고객 ID관련 주문이 없습니다]" << endl;
		cout << LINE << endl;

		break;  //case 1 종료

	case 2:
		cout << "검색할 제품코드를 입력하세요 : ";
		cin >> input;


		system("cls");
		cout << LINE << endl;
		cout << "                                            제품 코드 검색결과                             " << endl;
		cout << LINE << endl;
		print_Shopmenu();		//주문내역 테이블 메뉴

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
		{
			if ((*it)->getProductID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if ((*pit)->getProductID().find(input) != -1) {// 클라이언트 ID와 입력한 input 문자열에 겹치는게 있으면
						flag = true;
						if (p_ID == (*pit)->getProductID()) {
							productname = (*pit)->getProductName();
							producttype = (*pit)->getProductType();
							price = (*pit)->getPrice();
							sum = price * (*it)->getStock();
						}
					}
				}
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if (c_ID == (*cit)->getclientID()) {
						name = (*cit)->getName();
						phonenumber = (*cit)->getPhoneNumber();
						address = (*cit)->getAddress();
					}
				}

				cout.setf(ios::left); //좌측 정렬 후 출력
				cout << " #" << setw(27) << (*it)->getShopkey() << setw(15) << (*it)->getProductID() << setw(15) << (*it)->getproductName() << setw(15)
					<< (*it)->getproductType() << setw(11) << (*it)->getPrice()
					<< setw(11) << (*it)->getStock() << setw(15) << sum << endl;
				cout << "  " << setw(27) << (*it)->getname() << setw(15) << (*it)->getclientID() << setw(15) << (*it)->getphoneNumber()
					<< (*it)->getaddress() << endl << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 제품코드 관련 주문이 없습니다]" << endl;
		cout << LINE << endl;
		break;
	}
}//void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList) 검색하기 함수



int ShopInfoManager::smenu()	// 쇼핑정보 메뉴에서 정해진 범위만 받도록
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
int ShopInfoManager::ssearach_menu()		// 검색 메뉴 입력 예외처리
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
void ShopInfoManager::print_Shopmenu()		//주문내역 테이블 메뉴
{
	cout.setf(ios::left); //좌측 정렬 후 출력
	cout << setw(29) << " 주문번호(PK)" << setw(15) << "제품코드" << setw(15) << "제품명" << setw(15) << "제품종류" << setw(11) << "가격"
		<< setw(11) << "주문수량" << setw(11) << "주문가격" << endl;
	cout << setw(29) << " 고객명" << setw(15) << "고객ID" << setw(15) << "전화번호" << "주소" << endl;
	cout << LINE << endl;
}

vector<string> ShopInfoManager::parseCSV(istream& file, char delimiter)
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