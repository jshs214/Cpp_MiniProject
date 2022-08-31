#include "Product.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ProductManager {
public:
	void add_Product()		// 제품 추가
	{
		string productID;
		string productName;
		int price;
		int stock;
		string productType;

		system("cls");
		cout << LINE << endl;
		cout << "                           신규 제품 등록                             " << endl;
		cout << LINE << endl;

		cout << "제품코드 (PK) : "; cin >> productID;
		cout << "제품명 : "; cin >> productName;
		cout << "가격 : "; cin >> price;
		cout << "수량 : "; cin >> stock;
		cout << "종류 : "; cin >> productType;

		while (1) {
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
				cout << " 중복되는 제품 ID 입니다. 다시 입력해 주세요 : ";
				cin >> productID;
			}
		}

		Product* newProduct = new Product(productID, productName, price, stock, productType);
		productList.push_back(newProduct);

		cout << "[제품 등록 완료]" << endl;

		Sleep(1000);	//Delay 1초
	}

	void Product_print()		// 조회
	{
		system("cls");
		cout << LINE << endl;
		cout << "                               제품정보조회                             " << endl;
		cout << LINE << endl;
		cout << "    제품코드 (PK)     /   제품명   /   가격     /   수량   /   종류" << endl;
		cout << LINE << endl;
		for_each(productList.begin(), productList.end(), [](Product* p) {
			cout << "제품코드 : " << p->getProductID() << " / "
				<< "제품명 : " << p->getProductName() << " / "
				<< "가격 : " << p->getPrice() << " / "
				<< "수량 : " << p->getStock() << " / "
				<< "종류 : " << p->getProductType() << endl;
			});
		cout << "[제품정보 조회 완료]" << endl;
		cout << LINE << endl;
		cout << "총 " << productList.size() << "건의 제품정보가 있습니다" << endl;
		cout << LINE << endl;
	}


	void search_Product()		// 검색
	{
		string input;
		int sch_num;		//검색할 정보
		bool flag = 0;

		system("cls");
		cout << LINE << endl;
		cout << "                             제품 검색                             " << endl;
		cout << LINE << endl;
		cout << "1. 제품명 검색 2. 종류 검색 "; cin >> sch_num;

		switch (sch_num)
		{
		case 1:
			cout << "제품명 검색 : "; cin >> input;
			for (auto it = productList.begin(); it != productList.end(); ++it)
			{
				auto sch_name = (*it)->getProductName();
				if (sch_name.find(input) != -1) {
					flag = true;
					cout << (*it)->getProductID() << " : "
						<< (*it)->getProductName() << " / "
						<< (*it)->getPrice() << " / "
						<< (*it)->getStock() << " / "
						<< (*it)->getProductType() <<endl;
				}
			}
			if (flag == false)
				cout << "입력하신 제품명이 없습니다" << endl;
			cout << LINE << endl;
			break;		// case 1 break;

		case 2:
			cout << "종류 검색 : "; cin >> input;
			for (auto it = productList.begin(); it != productList.end(); ++it)
			{
				auto sch_type = (*it)->getProductType();
				if (sch_type.find(input) != -1) {
					flag = true;
					cout << (*it)->getProductID() << " : "
						<< (*it)->getProductName() << " / "
						<< (*it)->getPrice() << " / "
						<< (*it)->getStock() << " / "
						<< (*it)->getProductType() << endl;
				}
			}
			if (flag == false)
				cout << "입력하신 제품의 종류가 없습니다" << endl;
			cout << LINE << endl;
			break;		// case 2 break;
		}
	}

	void delete_Product()		//삭제
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             제품 정보 삭제                              " << endl;
		cout << LINE << endl;
		string input;
		bool flag = 0;
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
			cout << "입력하신 제품 ID가 없습니다" << endl;
		cout << LINE << endl;
	}

	void update_product()	//정보 변경
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             제품 정보 변경                              " << endl;
		cout << LINE << endl;
		string input;	//제품 ID 비교 변수
		int up_num;	// 업데이트정보 구분위한 변수
		int up_data;	// 업데이트 할 데이터
		bool flag = 0;

		cout << "제품 ID 입력 : "; cin >> input;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_name = (*it)->getProductID();		//입력한 제품 ID 데이터가 있으면

			if (sch_name == input) {
				flag = true;
				cout << "1. 가격 변경  2. 개수 변경 " << endl;
				cin >> up_num;	//변경할 정보

				switch (up_num)
				{
				case 1:		//가격 변경
					cout << "변경 가격 입력 : " ;		cin >> up_data;
					(*it)->setPrice(up_data);
					cout << "[가격 변경 완료]" << endl;
					break;

				case 2:		//수량 변경
					cout << "변경할 수량 입력 : " ;	cin >> up_data;
					(*it)->setStock(up_data);
					cout << "[수량 변경 완료]" << endl;
					break;

				}
			}
			if (flag == false)
				cout << "입력하신 제품 ID가 없습니다" << endl;

			cout << LINE << endl;
		}
	}

private:
	vector<Product*>productList;
};