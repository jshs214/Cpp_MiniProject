#include "Product.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ProductManager {
public:
	void add_Product()		// ��ǰ �߰�
	{
		string productID;
		string productName;
		int price;
		int stock;
		string productType;

		system("cls");
		cout << LINE << endl;
		cout << "                           �ű� ��ǰ ���                             " << endl;
		cout << LINE << endl;

		cout << "��ǰ�ڵ� (PK) : "; cin >> productID;
		cout << "��ǰ�� : "; cin >> productName;
		cout << "���� : "; cin >> price;
		cout << "���� : "; cin >> stock;
		cout << "���� : "; cin >> productType;

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
				cout << " �ߺ��Ǵ� ��ǰ ID �Դϴ�. �ٽ� �Է��� �ּ��� : ";
				cin >> productID;
			}
		}

		Product* newProduct = new Product(productID, productName, price, stock, productType);
		productList.push_back(newProduct);

		cout << "[��ǰ ��� �Ϸ�]" << endl;

		Sleep(1000);	//Delay 1��
	}

	void Product_print()		// ��ȸ
	{
		system("cls");
		cout << LINE << endl;
		cout << "                               ��ǰ������ȸ                             " << endl;
		cout << LINE << endl;
		cout << "    ��ǰ�ڵ� (PK)     /   ��ǰ��   /   ����     /   ����   /   ����" << endl;
		cout << LINE << endl;
		for_each(productList.begin(), productList.end(), [](Product* p) {
			cout << "��ǰ�ڵ� : " << p->getProductID() << " / "
				<< "��ǰ�� : " << p->getProductName() << " / "
				<< "���� : " << p->getPrice() << " / "
				<< "���� : " << p->getStock() << " / "
				<< "���� : " << p->getProductType() << endl;
			});
		cout << "[��ǰ���� ��ȸ �Ϸ�]" << endl;
		cout << LINE << endl;
		cout << "�� " << productList.size() << "���� ��ǰ������ �ֽ��ϴ�" << endl;
		cout << LINE << endl;
	}


	void search_Product()		// �˻�
	{
		string input;
		int sch_num;		//�˻��� ����
		bool flag = 0;

		system("cls");
		cout << LINE << endl;
		cout << "                             ��ǰ �˻�                             " << endl;
		cout << LINE << endl;
		cout << "1. ��ǰ�� �˻� 2. ���� �˻� "; cin >> sch_num;

		switch (sch_num)
		{
		case 1:
			cout << "��ǰ�� �˻� : "; cin >> input;
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
				cout << "�Է��Ͻ� ��ǰ���� �����ϴ�" << endl;
			cout << LINE << endl;
			break;		// case 1 break;

		case 2:
			cout << "���� �˻� : "; cin >> input;
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
				cout << "�Է��Ͻ� ��ǰ�� ������ �����ϴ�" << endl;
			cout << LINE << endl;
			break;		// case 2 break;
		}
	}

	void delete_Product()		//����
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             ��ǰ ���� ����                              " << endl;
		cout << LINE << endl;
		string input;
		bool flag = 0;
		cout << "������ ��ǰ ID �Է��ϼ��� : "; cin >> input;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_ID = (*it)->getProductID();
			if (sch_ID == input) {
				flag = true;
				productList.erase(it);
				cout << input << " �� ���� ������ �����Ǿ����ϴ�." << endl;
				cout << "[��ǰ���� ���� �Ϸ�]" << endl;
				break;
			}
		}
		if (flag == false)
			cout << "�Է��Ͻ� ��ǰ ID�� �����ϴ�" << endl;
		cout << LINE << endl;
	}

	void update_product()	//���� ����
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             ��ǰ ���� ����                              " << endl;
		cout << LINE << endl;
		string input;	//��ǰ ID �� ����
		int up_num;	// ������Ʈ���� �������� ����
		int up_data;	// ������Ʈ �� ������
		bool flag = 0;

		cout << "��ǰ ID �Է� : "; cin >> input;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_name = (*it)->getProductID();		//�Է��� ��ǰ ID �����Ͱ� ������

			if (sch_name == input) {
				flag = true;
				cout << "1. ���� ����  2. ���� ���� " << endl;
				cin >> up_num;	//������ ����

				switch (up_num)
				{
				case 1:		//���� ����
					cout << "���� ���� �Է� : " ;		cin >> up_data;
					(*it)->setPrice(up_data);
					cout << "[���� ���� �Ϸ�]" << endl;
					break;

				case 2:		//���� ����
					cout << "������ ���� �Է� : " ;	cin >> up_data;
					(*it)->setStock(up_data);
					cout << "[���� ���� �Ϸ�]" << endl;
					break;

				}
			}
			if (flag == false)
				cout << "�Է��Ͻ� ��ǰ ID�� �����ϴ�" << endl;

			cout << LINE << endl;
		}
	}

private:
	vector<Product*>productList;
};