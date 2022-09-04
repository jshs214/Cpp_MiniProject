#include "ShopInfoManager.h"

#include <vector>
#include <algorithm>

int ssearach_menu();		// ShopInfo �˻� �޴� �Է� ����ó��
vector<ShopInfo*> ShopInfoManager::getShopInfolist()
{
	return ShopInfolist;
}

void ShopInfoManager::add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // �ֹ��ϱ�
{
	int shopkey;	//ShopInfo�� PKŰ
	string cid, pid;	// �Է¹��� ClientID�� ProductID ����
	int stock;		//����
	int cinput = 0; //��ġ�ϴ��� flag
	int pinput = 0; //��ġ�ϴ��� flag

	bool cflag = false;
	bool pflag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                           �ֹ�                             " << endl;
	cout << LINE << endl;


	shopkey = 1000;		//ShopInfo�� ���� �⺻Ű(PKŰ)
	cout << "�� ID : "; cin >> cid;   // ClientID PK�˻縦 ���� cin
	cout << "��ǰ ID : "; cin >> pid;   // ProductID PK�˻縦 ���� pin
	cout << "������ ��ǰ ���� : "; cin >> stock;

	while (1) {
		cflag = false;
		cinput = 0;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_cid = (*it)->getclientID();
			if (sch_cid == cid) {           // ClientID�� �Է��� id�� ������
				cflag = true;
				cinput++;
				break;
			}
		}
		if (cflag == true)	break;
		else
		{
			cout << "�� ID�� �����ϴ�. ���Է� ���ּ��� (���� 0) : ";
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
			if (sch_pid == pid) {           // ClientID�� �Է��� id�� ������
				pflag = true;
				pinput++;
				break;
			}
		}
		if (pflag == true)	break;
		else
		{
			cout << "��ǰ ID�� �����ϴ�. ���Է� ���ּ��� (���� 0) :";
			cin >> pid;
		}
		if (pid == "0") return;
	}


	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //�ֹ����� PK �ߺ��˻�
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


	cout << "[�ֹ� �Ϸ�]" << endl;

	Sleep(1000);	//Delay 1��
}//void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // �ֹ��ϱ� �Լ� ����


void ShopInfoManager::shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // ��ȸ
{
	string name;            //Client ����
	string phonenumber;     //  ��ȭ��ȣ
	string address;         //  �ּ�
	string productname;     //Product ��ǰ��
	string producttype;  // ����
	int price;           //  ��ǰ ����
	int sum = 0;   //����

	system("cls");
	cout << LINE << endl;
	cout << "                               ��ǰ������ȸ                             " << endl;
	cout << LINE << endl;
	cout << " �ֹ���ȣ(PK)  /  ��ID  /  ����  /  ��ǰ�ڵ�  /  ��ǰ��  /  ����  /  ����  /  ��������  /  ��ȭ��ȣ  /  �ּ�" << endl;
	cout << LINE << endl;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
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
			<< (*it)->getStock() << " / " << "�� �� : " << sum << " / "
			<< phonenumber << " / " << address << endl;
	}

	cout << "[�ֹ����� ��ȸ �Ϸ�]" << endl;
	cout << LINE << endl;
	cout << "[�� " << ShopInfolist.size() << "���� �ֹ��� �ֽ��ϴ�.]" << endl;
	cout << LINE << endl;
}//void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // ��ȸ�ϱ� �Լ� ����

void ShopInfoManager::search_shoplist(vector<Client*>& clientList, vector<Product*>& productList)    //�˻�
{
	string name;            //Client ����
	string phonenumber;     //  ��ȭ��ȣ
	string address;         //  �ּ�
	string productname;     //Product ��ǰ��
	string producttype;  // ����

	string shopid;
	int price;           //  ��ǰ ����
	int sum = 0;   //����

	bool flag = false;
	int num = 0;
	string input;	//�˻� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������

	system("cls");
	cout << LINE << endl;
	cout << "                             �ֹ����� �˻�                             " << endl;
	cout << LINE << endl;
	cout << "1. �� ID �˻� 2. ��ǰ�ڵ� �˻� ";

	num = ssearach_menu();		// �˻� �޴� �Է� ����ó��

	switch (num) {
	case 1:
		cout << "�˻��� �� ID�� �Է��ϼ��� : ";
		cin >> input;
		
		system("cls");
		cout << LINE << endl;
		cout << "                             �� ID �˻����                             " << endl;
		cout << LINE << endl;
		cout << " �ֹ���ȣ(PK)  /  ��ID  /  ����  /  ��ǰ�ڵ�  /  ��ǰ��  /  ����  /  ����  /  ��������  /  ��ȭ��ȣ  /  �ּ�" << endl;
		cout << LINE << endl;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
		{
			if ((*it)->getclientID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = clientList.begin(); cit != clientList.end(); ++cit)
				{
					if ((*cit)->getclientID().find(input) != -1) {// Ŭ���̾�Ʈ ID�� �Է��� input ���ڿ��� ��ġ�°� ������
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
					<< (*it)->getStock() << " / " << "�������� : " << sum << " / "
					<< phonenumber << " / " << address << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �� ID�� �����ϴ�]" << endl;
		cout << LINE << endl;

		break;  //case 1 ����

	case 2:
		cout << "�˻��� ��ǰ�ڵ带 �Է��ϼ��� : ";
		cin >> input;


		system("cls");
		cout << LINE << endl;
		cout << "                             ��ǰ �ڵ� �˻����                             " << endl;
		cout << LINE << endl;
		cout << " �ֹ���ȣ(PK)  /  ��ID  /  ����  /  ��ǰ�ڵ�  /  ��ǰ��  /  ����  /  ����  /  ��������  /  ��ȭ��ȣ  /  �ּ�" << endl;
		cout << LINE << endl;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
		{
			if ((*it)->getProductID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto pit = productList.begin(); pit != productList.end(); ++pit)
				{
					if ((*pit)->getProductID().find(input) != -1) {// Ŭ���̾�Ʈ ID�� �Է��� input ���ڿ��� ��ġ�°� ������
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
					<< (*it)->getStock() << " / " << "�������� : " << sum << " / "
					<< phonenumber << " / " << address << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� ��ǰ�ڵ尡 �����ϴ�]" << endl;
		cout << LINE << endl;
		break;
	}
}//void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList) �˻��ϱ� �Լ�


int ssearach_menu()		// �˻� �޴� �Է� ����ó��
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