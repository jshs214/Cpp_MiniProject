#define _CRT_SECURE_NO_WARNINGS
#include "ShopInfoManager.h"

#include<iostream>
#include <vector>
#include <algorithm>
#include<fstream>
#include<sstream>
#include <iomanip>
#include <ctime>


ShopInfoManager::ShopInfoManager(ClientManager& cm,ProductManager& pm)		//ShopInfoManager 생성자에서 파일 load
	:CM(cm), PM(pm)
{
	ifstream file;
	file.open("ShopInfo.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int shopkey = atoi(row[0].c_str());		// 파일입출력을 위한 int형  형변환
				int price = atoi(row[4].c_str());		
				int stock = atoi(row[5].c_str());		
				int year = atoi(row[10].c_str());		
				int month = atoi(row[11].c_str());		
				int day = atoi(row[12].c_str());		
				ShopInfo* s = new ShopInfo(shopkey, row[1], row[2], row[3], price, stock, 
											row[6], row[7], row[8], row[9],year,month,day);
				ShopInfolist.push_back(s);
			}
		}
	}
	cout << "ShopInfo.txt을 로드하였습니다." << endl;
	Sleep(1000);
	file.close();
}

ShopInfoManager::~ShopInfoManager()			//ShopInfoManager 소멸자에서 파일 입력
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
			<<(*it)->getaddress() << ", " << (*it)->getyear() << ", " << (*it)->getmonth() << ", " << (*it)->getday()  << ", " <<endl;
	}
	cout << "ShopInfo.txt을 저장했습니다." << endl;
	Sleep(1000);
	fs.close();
}

void ShopInfoManager::ShopMainMenu()	//ShopInfo 화면
{
	int shoping_menu;	// 1. 주문 2. 조회 3. 검색 4. 변경 5. 삭제
	int back = 0;
	shoping_menu = smenu();	//쇼핑정보메뉴에서 1 ~ 5만 받는 함수
	switch (shoping_menu)
	{
	case 1:		// 주문
		add_Shoplist();
		break;
	case 2:		//주문내역 조회
		shoplist_print();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	case 3:		//주문내역 검색
		search_shoplist();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	case 4:		//주문내역 변경
		update_shop();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	case 5:		// 주문 내역 삭제
		delete_shoplist();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	}
}
void ShopInfoManager::add_Shoplist()       // ShopInfolist벡터에 데이터를 push_back 하는 주문 함수
{
	int shopkey=1000, stock = 0,price =0;
	string productid, productname, producttype, name, clientid, phonenumber, address;

	string cid, pid;	// 입력받을 ClientID와 ProductID 변수
	int up_stock;
	int cinput = 0, pinput=0, sinput=0; // 각 클래스 PK키가 있는지 검사하기 위한 변수

	time_t timer;			// 시간을 위한 변수
	struct tm* t;
	timer = time(NULL); // 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초
	t = localtime(&timer); 
	int tm_year, tm_mon, tm_mday;
	tm_year = t->tm_year + 1900;	tm_mon = t->tm_mon + 1;	tm_mday = t->tm_mday;	// 연, 월, 일

	bool cflag = false, pflag=false;	//경계검사를위한 변수
	
	system("cls");
	cout << LINE << endl;
	cout << "                                            주문                             " << endl;
	cout << LINE << endl;

	cout << "고객 ID : "; cin >> cid;
	cout << "제품 ID : "; cin >> pid;
	cout << "구매할 제품 개수 : "; cin >> stock;

	while (1) {					//Client ID 중복검사 ( 같아야 진행 )
		cflag = false;
		cinput = 0;
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
		else  //없으면 ClientID 재입력
		{
			cout << "고객 ID가 없습니다. 재입력 해주세요 (종료 0) : ";
			cin >> cid;	
		}

		if (cid == "0")    return;		//종료조건
	}

	while (1) {					//Product ID 중복검사 ( 같아야 진행 )
		pflag = false;
		pinput = 0;
		for (auto it = PM.getproductList().begin(); it != PM.getproductList().end(); ++it)
		{
			auto sch_pid = (*it)->getProductID();
			if (sch_pid == pid) {           // ProductID와 입력한 id가 같으면
				pflag = true;
				pinput++;
				break;
			}
		}
		if (pflag == true)	break;
		else  //없으면 ProductID 재입력
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
	
	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //주문내역 PK키 중복검사
	{
		auto sch_shopkey = (*it)->getShopkey();
		if (sch_shopkey == shopkey) {		//키값이 있으면 1 증가
			shopkey++;
		}
	}
	
	for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {				// 주문 할 때 Product 벡터의 재고가 빠지는 동작
		auto id = (*pit)->getProductID();
		if (pid == id) {			// 입력한 pid와 Product 벡터의 ID 같으면 Product 벡터의 재고 수정
			while (1) {
				sinput = 0;// 주문수량보다 재고가 많은지 체크
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
	
	if (cinput > 0 && pinput > 0&& sinput > 0) {			// Client, Product가 정상적으로 생성되고, 재고가 정상적이면 주문.
		ShopInfo* newShopC = new ShopInfo(shopkey, productid, productname, producttype,	
											price, stock, name, clientid, phonenumber, address,tm_year,tm_mon,tm_mday);
		ShopInfolist.push_back(newShopC);
	}
	Sleep(1000);
}

void ShopInfoManager::shoplist_print()     // ShopInfolist 벡터 조회
{
	int sum = 0;

	system("cls");
	cout << LINE << endl;
	cout << "                                            주문내역 정보조회" << endl;
	cout << LINE << endl;

	print_Shopmenu();		//주문내역 디자인메뉴 출력

	sort(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* a, ShopInfo* b) {		//주문번호 ,날짜 기준으로 정렬	
		if (a->getyear() == b->getyear() && a->getmonth() == b->getmonth() && a->getday() == b->getday()) {	// 날짜가 같으면 주문번호 key값으로 오름차순
			return a->getShopkey() < b->getShopkey();
		}
		else if (a->getyear() == b->getyear()) {	//날짜가 다르면 날짜로 오름차순
			if (a->getmonth() == b->getmonth()) {
				return a->getday() < b->getday();
			}
			else
				return a->getmonth() < b->getmonth();
		}
		else  return a->getyear() < b->getyear();
		});

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    
	{
		showShoplist(*it); //Shoplist 벡터 출력 함수
	}

	cout << "[주문내역 조회 완료]" << endl;
	cout << LINE << endl;
	cout << "[총 " << ShopInfolist.size() << "건의 주문이 있습니다.]" << endl;
	cout << LINE << endl;
}

void ShopInfoManager::search_shoplist()    // ShopInfolist 검색
{
	int price, sum = 0;
	string name, phonenumber, address, productname, producttype; 
	string input;	//검색 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수

	int num = 0;	//어떤 조건을 검사할지 switch case 변수
	bool flag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                                            주문내역 검색" << endl;
	cout << LINE << endl;
	cout << "1. 고객 ID 검색 2. 제품코드 검색 ";

	num = ssearach_menu();		// 검색 메뉴 입력 예외처리
	switch (num) {
	case 1:
		cout << "검색할 고객 ID를 입력하세요 : ";
		cin >> input;	// Client벡터에 있는 ID와 비교하기 위한 변수
		
		system("cls");
		cout << LINE << endl;
		cout << "                                       [입력한 고객 ID : "<<input<<" 검색결과]"  << endl;
		cout << LINE << endl;
		print_Shopmenu();		//주문내역 디자인메뉴 출력

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it) 
		{
			if ((*it)->getclientID().find(input) != -1)		// 입력한 input 문자열이 ShopInfolist벡터의 clientID가 포함되면 동작.
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if ((*cit)->getclientID().find(input) != -1) {// 입력한 문자열이 ShopInfolist벡터의 ClientID에 포함되면
						flag = true;
						if (c_ID == (*cit)->getclientID()) {	// Client 벡터가 가리키는 데이터 가져옴
							name = (*cit)->getName();
							phonenumber = (*cit)->getPhoneNumber();
							address = (*cit)->getAddress();
						}
					}
				}
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if (p_ID == (*pit)->getProductID()) {		// Product 벡터가 가리키는 데이터 가져옴
						productname = (*pit)->getProductName();
						producttype = (*pit)->getProductType();
						price = (*pit)->getPrice();
						sum = price * (*it)->getStock();
					}
				}
				showShoplist(*it);	//ShopInfolist 벡터 출력
			}
		}
		if (flag == false)
			cout << "[입력하신 고객 ID관련 주문이 없습니다]" << endl;
		cout << LINE << endl;
		break;  //case 1 종료
	case 2:
		cout << "검색할 제품코드를 입력하세요 : ";
		cin >> input;	// Product벡터에 있는 ID와 비교하기 위한 변수

		system("cls");
		cout << LINE << endl;
		cout << "                                       [입력한 제품코드 : " << input << " 검색결과]" << endl;
		cout << LINE << endl;
		print_Shopmenu();		//주문내역 디자인 메뉴

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getProductID().find(input) != -1)	// 입력한 문자열이 ShopInfolist벡터의 ProductID에 포함되면
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();	
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if ((*pit)->getProductID().find(input) != -1) {	// 입력한 문자열이 Product벡터의 ID에 포함되면
						flag = true;
						if (p_ID == (*pit)->getProductID()) {	// Product 벡터가 가리키는 데이터 가져옴
							productname = (*pit)->getProductName();
							producttype = (*pit)->getProductType();
							price = (*pit)->getPrice();
							sum = price * (*it)->getStock();
						}
					}
				}
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if (c_ID == (*cit)->getclientID()) {		// Client 벡터가 가리키는 데이터 가져옴
						name = (*cit)->getName();
						phonenumber = (*cit)->getPhoneNumber();
						address = (*cit)->getAddress();
					}
				}

				showShoplist(*it);	//ShopInfolist 벡터 출력
			}
		}
		if (flag == false)
			cout << "[입력하신 제품코드 관련 주문이 없습니다]" << endl;
		cout << LINE << endl;
		break;	//case2 종료.
	case 3: 		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000); break;
	}
}//검색하기 함수 종료

void ShopInfoManager::update_shop()	//주문정보 변경 함수
{
	int input;
	int up_stock;	// 변경 시 업데이트할 수량 변수
	string up_data;	// 변경 시 업데이트할 주소, 연락처 변수
	int num;	//어떤 조건을 검사할지 switch case 변수
	bool flag = false;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 출력
	{
			showShoplist(*it);
	}
	cout << LINE << endl;
	cout << " 1. 재고변경, 2. 수령인 연락처 변경 3. 배송지 변경 ";

	num=ssearach_menu();	// 1,2,3 외에 입력 예외 처리
	switch (num) {
	case 1:	// 재고변경
		cout << "재고변경할 주문번호를 입력하세요 : "; cin >> input;

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PK키와 입력값이 같으면 재고 변경 동작
				flag = true;
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {
					auto sid = (*it)->getProductID();
					auto pid = (*pit)->getProductID();
					if (sid == pid) {	//가져온 ShopInfo의 제품코드를 Product에있는 제품코드와 매칭
						cout << "변경 수량 입력 : ";	cin >> up_stock;

						if (up_stock <= 0) {
							cout << "[변경 수량이 0보다 같거나 작습니다]" << endl;
						}
						else {
							if (up_stock > (*pit)->getStock() + (*it)->getStock()) {	// 변경할 수량이 Product의 재고 + 현재 주문재고 보다 크면
								cout << "[현재 재고보다 주문하신 수량이 더 많습니다. " 
									<<"변경가능 최대 수량 : "<<(*pit)->getStock() + (*it)->getStock() <<"]" << endl;
							}
							else {
								int stock = (*pit)->getStock() + (*it)->getStock();		// 재고를 변경 전 제품의 재고 + 기존 주문내역 재고로 변경
								(*pit)->setStock(stock);		//product에 있는 재고에 수정한 재고를
								(*it)->setStock(up_stock);		//Shoplist 주문수량으로 변경

								int up_stock = (*pit)->getStock() - (*it)->getStock();	// 제품재고 - 변경한 주문수량 
								(*pit)->setStock(up_stock);
								cout << "[수량이 변경되었습니다.]" << endl;
							}
							break;
						}
					}
				}
			}
		}
		if (flag == false)
			cout << "[입력하신 주문번호가 없습니다]" << endl;
		break;
	case 2:	// 연락처변경
		cout << "수령인 연락처 변경할 주문번호를 입력하세요 : "; cin >> input;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PK키와 입력값이 같으면 전화번호 변경 동작
				flag = true;
				cout << "변경할 수령인 연락처 입력 : "; cin >> up_data;
				(*it)->setphoneNumber(up_data);
				cout << endl << "[수령인 연락처가 변경되었습니다.]" << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 주문번호가 없습니다]" << endl;
		break;
	case 3:	// 배송지주소 변경
		cout << "수령인 배송지 변경할 주소를 입력하세요 : "; cin >> input;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PK키와 입력값이 같으면 주소 변경동작
				flag = true;
				cout << "변경할 배송지 재입력 : "; cin.ignore(); getline(cin, up_data);
				(*it)->setaddress(up_data);
				cout << endl << "[배송지가 변경되었습니다.]" << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 주문번호가 없습니다]" << endl;
		break;	//case 3 종료
	}
}	//주문정보 변경 함수 종료
void ShopInfoManager::delete_shoplist() {	//삭제 함수
	int input;
	bool flag = false;
	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 출력
	{
		showShoplist(*it);
	}
	cout << LINE << endl;
	cout << "삭제할 주문번호 입력하세요 : "; cin >> input;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
	{
		auto sch_ID = (*it)->getShopkey();
		if (sch_ID == input) {	// ShopInfolist의 주문번호 키와 입력값이 같으면 주문정보 삭제 동작
			flag = true;
			ShopInfolist.erase(it);
			cout << input << " 에 대한 주문정보가 삭제되었습니다." << endl;
			cout << "[주문정보 삭제 완료]" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "[입력하신 주문번호가 없습니다]" << endl;
	cout << LINE << endl;
}
void ShopInfoManager::showShoplist(ShopInfo* shopinfo)		//ShopInfolist 출력 해주는 함수
{
	int sum = 0;
	sum = shopinfo->getPrice() * shopinfo->getStock();
	cout.setf(ios::left); //좌측 정렬
	cout << " #" << setw(27) << shopinfo->getShopkey() << setw(15) << shopinfo->getProductID() << setw(15) << shopinfo->getproductName() << setw(15)
		<< shopinfo->getproductType() << setw(11) << shopinfo->getPrice()
		<< setw(11) << shopinfo->getStock() << setw(15) << sum << endl;
	cout << "  " << shopinfo->getyear() << "." << shopinfo->getmonth() << "." << setw(10) << shopinfo->getday() << setw(10) <<
		shopinfo->getname() << setw(15) << shopinfo->getclientID() << setw(15) << shopinfo->getphoneNumber()
		<< shopinfo->getaddress() << endl << endl;
}

int ShopInfoManager::smenu()	// 메뉴에서 정해진 범위만 받도록
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
int ShopInfoManager::ssearach_menu() // 메뉴에서 정해진 범위만 받도록
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 4)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

void ShopInfoManager::print_Shopmenu()		//주문내역 디자인메뉴 출력
{
	cout.setf(ios::left); //좌측 정렬 후 출력
	cout << setw(29) << " 주문번호(PK)" << setw(15) << "제품코드" << setw(15) << "제품명" << setw(15) << "제품종류" << setw(11) << "가격"
		<< setw(11) << "주문수량" << setw(11) << "주문가격" << endl;
	cout << setw(19) << "  날짜"<<setw(10) << "고객명" << setw(15) << "고객ID" << setw(15) << "전화번호" << "주소" << endl;
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