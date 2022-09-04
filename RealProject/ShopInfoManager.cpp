#include "ShopInfoManager.h"

#include <vector>
#include <algorithm>


vector<ShopInfo*> ShopInfoManager::getShopInfolist()
{
	return ShopInfolist;
}

void ShopInfoManager::add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // 주문하기
{
	int shopkey;	//ShopInfo의 PK키
	string cid, pid;	// 입력받을 ClientID와 ProductID 변수
	int stock;		//수량
	int cinput = 0; //일치하는지 flag
	int pinput = 0; //일치하는지 flag

	bool cflag = false;
	bool pflag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                           주문                             " << endl;
	cout << LINE << endl;


	shopkey = 1000;		//ShopInfo에 대한 기본키(PK키)
	cout << "고객 ID : "; cin >> cid;   // ClientID PK검사를 위한 cin
	cout << "제품 ID : "; cin >> pid;   // ProductID PK검사를 위한 pin
	cout << "구매할 제품 개수 : "; cin >> stock;

	while (1) {
		cflag = false;
		cinput = 0;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
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

		if (cid == "0")    return;
	}

	while (1) {
		pflag = false;
		pinput = 0;
		for (auto it = productList.begin(); it != productList.end(); ++it)
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
		if (pid == "0") return;
	}


	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //주문내역 PK 중복검사
	{
		auto sch_shopkey = (*it)->getShopkey();
		if (sch_shopkey == shopkey) {
			shopkey++;
		}
	}

	if (cinput > 0 && pinput > 0) {
		ShopInfo* newShopC = new ShopInfo(shopkey, cid, pid, stock);
		ShopInfolist.push_back(newShopC);
	}


	cout << "[주문 완료]" << endl;

	Sleep(1000);	//Delay 1초
}//void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // 주문하기 함수 종료


void ShopInfoManager::shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 조회
{
	string name;            //Client 고객명
	string phonenumber;     //  전화번호
	string address;         //  주소
	string productname;     //Product 제품명
	string producttype;  // 종류
	int price;           //  제품 가격
	int sum = 0;   //총합

	system("cls");
	cout << LINE << endl;
	cout << "                               제품정보조회                             " << endl;
	cout << LINE << endl;
	cout << " 주문번호(PK)  /  고객ID  /  고객명  /  제품코드  /  제품명  /  종류  /  가격  /  결제가격  /  전화번호  /  주소" << endl;
	cout << LINE << endl;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
	{

		for (auto cit = clientList.begin(); cit != clientList.end(); ++cit)
		{
			if ((*it)->getclientID() == (*cit)->getclientID())
			{
				name = (*cit)->getName();
				phonenumber = (*cit)->getPhoneNumber();
				address = (*cit)->getAddress();
				break;
			}
		}
		for (auto pit = productList.begin(); pit != productList.end(); ++pit)
		{
			if ((*it)->getProductID() == (*pit)->getProductID())
			{
				productname = (*pit)->getProductName();
				producttype = (*pit)->getProductType();
				price = (*pit)->getPrice();
				sum = price * (*it)->getStock();
				break;
			}
		}

		cout << "NO." << (*it)->getShopkey() << " / " << (*it)->getclientID() << " / " << name << " / " << (*it)->getProductID() << " / "
			<< productname << " / " << producttype << " / " << price << " / "
			<< (*it)->getStock() << " / " << "총 합 : " << sum << " / "
			<< phonenumber << " / " << address << endl;
	}

	cout << "[주문내역 조회 완료]" << endl;
	cout << LINE << endl;
	cout << "[총 " << ShopInfolist.size() << "건의 주문이 있습니다.]" << endl;
	cout << LINE << endl;
}//void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 조회하기 함수 종료

void ShopInfoManager::search_shoplist(vector<Client*>& clientList, vector<Product*>& productList)    //검색
{
	string name;            //Client 고객명
	string phonenumber;     //  전화번호
	string address;         //  주소
	string productname;     //Product 제품명
	string producttype;  // 종류

	string shopid;
	int price;           //  제품 가격
	int sum = 0;   //총합

	bool flag = false;
	int num = 0;
	string input;	//검색 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수

	system("cls");
	cout << LINE << endl;
	cout << "                             주문내역 검색                             " << endl;
	cout << LINE << endl;
	cout << "1. 고객 ID 검색 2. 제품코드 검색"; cin >> num;
	switch (num) {
	case 1:
		cout << "검색할 고객 ID를 입력하세요 : ";
		cin >> input;
		
		system("cls");
		cout << LINE << endl;
		cout << "                             고객 ID 검색결과                             " << endl;
		cout << LINE << endl;
		cout << " 주문번호(PK)  /  고객ID  /  고객명  /  제품코드  /  제품명  /  종류  /  가격  /  결제가격  /  전화번호  /  주소" << endl;
		cout << LINE << endl;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
		{
			if ((*it)->getclientID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = clientList.begin(); cit != clientList.end(); ++cit)
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
				for (auto pit = productList.begin(); pit != productList.end(); ++pit)
				{
					if (p_ID == (*pit)->getProductID()) {

						productname = (*pit)->getProductName();
						producttype = (*pit)->getProductType();
						price = (*pit)->getPrice();
						sum = price * (*it)->getStock();
					}
				}
				cout << "NO." << (*it)->getShopkey() << " / " << (*it)->getclientID() << " / " << name << " / " << (*it)->getProductID() << " / "
					<< productname << " / " << producttype << " / " << price << " / "
					<< (*it)->getStock() << " / " << "결제가격 : " << sum << " / "
					<< phonenumber << " / " << address << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 고객 ID가 없습니다]" << endl;
		cout << LINE << endl;

		break;  //case 1 종료

	case 2:
		cout << "검색할 제품코드를 입력하세요 : ";
		cin >> input;


		system("cls");
		cout << LINE << endl;
		cout << "                             제품 코드 검색결과                             " << endl;
		cout << LINE << endl;
		cout << " 주문번호(PK)  /  고객ID  /  고객명  /  제품코드  /  제품명  /  종류  /  가격  /  결제가격  /  전화번호  /  주소" << endl;
		cout << LINE << endl;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
		{
			if ((*it)->getProductID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto pit = productList.begin(); pit != productList.end(); ++pit)
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
				for (auto cit = clientList.begin(); cit != clientList.end(); ++cit)
				{
					if (c_ID == (*cit)->getclientID()) {
						name = (*cit)->getName();
						phonenumber = (*cit)->getPhoneNumber();
						address = (*cit)->getAddress();
					}
				}

				cout << "NO." << (*it)->getShopkey() << " / " << (*it)->getclientID() << " / " << name << " / " << (*it)->getProductID() << " / "
					<< productname << " / " << producttype << " / " << price << " / "
					<< (*it)->getStock() << " / " << "결제가격 : " << sum << " / "
					<< phonenumber << " / " << address << endl;
			}
		}
		if (flag == false)
			cout << "[입력하신 제품코드가 없습니다]" << endl;
		cout << LINE << endl;
		break;
	}

}//void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList) 검색하기 함수


