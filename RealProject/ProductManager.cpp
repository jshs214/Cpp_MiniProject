#include "ProductManager.h"

#include<vector>
#include <algorithm>
int psearach_menu();		// �˻� �޴� �Է� ����ó��
ProductManager::ProductManager()
{

}
vector<Product*>& ProductManager::getproductList()
{
	return productList;
}

void ProductManager::add_Product()		// ��ǰ �߰�
{
	string productID;	// �Է��� ��ǰ�ڵ�
	string productName;	// ��ǰ ��
	int price = 0;			// ����
	string productType;		//��ǰ ����

	system("cls");
	cout << LINE << endl;
	cout << "                           �ű� ��ǰ ���                             " << endl;
	cout << LINE << endl;

	cout << "��ǰ�ڵ� (PK) : "; cin >> productID;
	cout << "��ǰ�� : "; cin >> productName;
	while (1) {
		cout << "���� : "; cin >> price;
		if (!cin) {		// cin menu �� ���ڸ� �Է� �޵���
			cout << "[���ڸ� �Է����ּ���]"<<endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			Sleep(1000);
		}
		else break;
	}
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

	Product* newProduct = new Product(productID, productName, price, productType);
	productList.push_back(newProduct);

	cout << "[��ǰ ��� �Ϸ�]" << endl;

	Sleep(1000);	//Delay 1��
}

void ProductManager::Product_print()		// ��ȸ
{
	system("cls");
	cout << LINE << endl;
	cout << "                               ��ǰ������ȸ                             " << endl;
	cout << LINE << endl;
	cout << "    ��ǰ�ڵ� (PK)     /   ��ǰ��   /   ����     /    ����" << endl;
	cout << LINE << endl;

	for_each(productList.begin(), productList.end(), [](Product* p) {
		cout << "��ǰ�ڵ� : " << p->getProductID() << " / "
			<< "��ǰ�� : " << p->getProductName() << " / "
			<< "���� : " << p->getPrice() << " / "
			<< "���� : " << p->getProductType() << endl;
		});

	cout << "[��ǰ���� ��ȸ �Ϸ�]" << endl;
	cout << LINE << endl;
	cout << "[�� " << productList.size() << "���� ��ǰ������ �ֽ��ϴ�]" << endl;
	cout << LINE << endl;
}


void ProductManager::search_Product()		// �˻�
{
	string input;	//�˻� �� �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	int num = 0;		//������ �˻����� switch case
	bool flag = 0;

	system("cls");
	cout << LINE << endl;
	cout << "                             ��ǰ �˻�                             " << endl;
	cout << LINE << endl;
	cout << "1. ��ǰ�� �˻� 2. ���� �˻� "; //cin >> num;

	num = psearach_menu();
	switch (num)
	{
	case 1:
		cout << "��ǰ�� �˻� : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                             ��ǰ�� �˻����                             " << endl;
		cout << LINE << endl;
		cout << "      ��ǰ�ڵ�(PK)     /   ��ǰ��    /    ����    /    ����" << endl;
		cout << LINE << endl;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_name = (*it)->getProductName();
			if (sch_name.find(input) != -1) {
				flag = true;
				cout << (*it)->getProductID() << " : "
					<< (*it)->getProductName() << " / "
					<< (*it)->getPrice() << " / "
					<< (*it)->getProductType() << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� ��ǰ���� �����ϴ�]" << endl;
		cout << LINE << endl;
		break;		// case 1 break;

	case 2:
		cout << "���� �˻� : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                             ���� �˻����                             " << endl;
		cout << LINE << endl;
		cout << "      ��ǰ�ڵ�(PK)     /   ��ǰ��    /    ����    /    ����" << endl;
		cout << LINE << endl;

		for (auto it = productList.begin(); it != productList.end(); ++it)
		{
			auto sch_type = (*it)->getProductType();
			if (sch_type.find(input) != -1) {
				flag = true;
				cout << (*it)->getProductID() << " : "
					<< (*it)->getProductName() << " / "
					<< (*it)->getPrice() << " / "
					<< (*it)->getProductType() << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� ��ǰ�� ������ �����ϴ�]" << endl;
		cout << LINE << endl;
		break;		// case 2 break;
	}
}

void ProductManager::delete_Product()		//����
{
	string input;	//���� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	bool flag = false;
	system("cls");
	cout << LINE << endl;
	cout << "                             ��ǰ ���� ����                              " << endl;
	cout << LINE << endl;

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
		cout << "[�Է��Ͻ� ��ǰ ID�� �����ϴ�]" << endl;
	cout << LINE << endl;
}

void ProductManager::update_product()	//���� ����
{
	string input;	//���� ���� �� �Է¹޴� ��ǰ ID ����
	int up_data;	//������Ʈ �� ���� �� ������
	bool flag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                             ��ǰ ���� ����                              " << endl;
	cout << LINE << endl;

	cout << "������ ��ǰ �ڵ� �Է� : "; cin >> input;

	for (auto it = productList.begin(); it != productList.end(); ++it)
	{
		auto sch_name = (*it)->getProductID();		//�Է��� ��ǰ ID �����Ͱ� ������

		if (sch_name == input) {
			flag = true;

			cout << "���� ���� �Է� : ";		cin >> up_data;
			(*it)->setPrice(up_data);
			cout << "[���� ���� �Ϸ�]" << endl;
			break;

		}
		if (flag == false)
			cout << "[�Է��Ͻ� ��ǰ �ڵ尡 �����ϴ�]" << endl;

		cout << LINE << endl;
	}
}

int psearach_menu()		// �˻� �޴� �Է� ����ó��
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu �� ���ڸ� �Է� �޵���
		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 3)
		return menu;
	else {
		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		Sleep(1000);
	}
	return 0;
}