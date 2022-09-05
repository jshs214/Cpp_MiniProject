#include "ShopInfoManager.h"

#include <vector>
#include <algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include <iomanip>

int ssearach_menu();		// ShopInfo �˻� �޴� �Է� ����ó��

ShopInfoManager::ShopInfoManager()
{
	ifstream file;
	file.open("ShopInfo.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int shopkey = atoi(row[0].c_str());		//PKŰ
				int stock = atoi(row[3].c_str());
				ShopInfo* s = new ShopInfo(shopkey, row[1], row[2], stock);
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
		cout << "����� ������ �� �� �����ϴ�.";
		Sleep(1000);
	}

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
	{
		fs << (*it)->getShopkey() << ", "
			<< (*it)->getclientID() << ", "
			<< (*it)->getProductID() << ", "
			<< (*it)->getStock() << endl;

	}
	fs.close();
}

vector<ShopInfo*> &ShopInfoManager::getShopInfolist()
{
	return ShopInfolist;
}

void ShopInfoManager::add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // �ֹ��ϱ�
{
	int shopkey;	//ShopInfo�� PKŰ
	string cid, pid;	// �Է¹��� ClientID�� ProductID ����
	int stock;		// �ֹ� �� ����
	int up_stock;	// ���ݿ��� �ʿ��� ����
	int cinput = 0; //��ġ�ϴ��� flag
	int pinput = 0; //��ġ�ϴ��� flag
	int sinput = 0;	//��ġ�ϴ��� flag
	bool cflag = false;
	bool pflag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ�                             " << endl;
	cout << LINE << endl;


	shopkey = 1000;		//ShopInfo�� ���� �⺻Ű(PKŰ)
	cout << "�� ID : "; cin >> cid;   // ClientID PK�˻縦 ���� cin
	cout << "��ǰ ID : "; cin >> pid;   // ProductID PK�˻縦 ���� pin
	cout << "������ ��ǰ ���� : "; cin >> stock;

	while (1) {					//Client ID �ߺ��˻� ( ���ƾ� ���� )
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

	while (1) {					//Product ID �ߺ��˻� ( ���ƾ� ���� )
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

	
	for (auto pit = productList.begin(); pit != productList.end(); ++pit) {				// �ֹ� �� �� Product�� ��� ������ ����
		auto id = (*pit)->getProductID();	////Product�� �ִ� ��ID
		if (pid == id) {			//pid�� �ֹ� �� �� �Է��� �� id
			while (1) {
				sinput = 0;

				if (((*pit)->getStock() - stock) < 0) {
					cout << "[�ֹ� ������ ����� �����ϴ�. " << (*pit)->getStock() << "�� ���ҽ��ϴ�.]" << endl;
					cout << "�ֹ� ������ ���Է� ���ּ��� (���� 0) :";
					cin >> stock;
					if (stock == 0)	break;
				}
				else {
					sinput++;
					up_stock = (*pit)->getStock() - stock;
					(*pit)->setStock(up_stock);
					cout << "[�ֹ� �Ϸ�]" << endl;
					break;
				}
			}
		}
	}
	
	if (cinput > 0 && pinput > 0&& sinput > 0) {			// Client, Product�� ���������� �����ǰ�, ��� �������̸� �ֹ�����Ʈ �߰�
		ShopInfo* newShopC = new ShopInfo(shopkey, cid, pid, stock);
		ShopInfolist.push_back(newShopC);
	}

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
	cout << "                                            ��ǰ������ȸ                             " << endl;
	cout << LINE << endl;

	cout.setf(ios::left); //���� ����
	cout <<  setw(29)<<" �ֹ���ȣ(PK)" << setw(15) << "��ǰ�ڵ�" << setw(15) << "��ǰ��" << setw(15) << "��ǰ����" << setw(11) << "����"
		<< setw(11)<<"�ֹ�����"<< setw(11)<< "�ֹ�����" << endl;
	cout << setw(29) << " ����" << setw(15) << "��ID" << setw(15) << "��ȭ��ȣ" << "�ּ�" <<   endl;
	cout << LINE << endl;

	sort(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* a, ShopInfo* b) {		//�ֹ���ȣ �������� ����
		return a->getShopkey() < b->getShopkey();
		});

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
		cout.setf(ios::left); //���� ����
		cout << " #" << setw(27) <<(*it)->getShopkey()<<setw(15) << (*it)->getProductID() << setw(15) << productname  << setw(15)
			<< producttype << setw(11) << price
			<< setw(11) << (*it)->getStock() <<setw(15) << sum << endl;
		cout <<"  " << setw(27) << name << setw(15) << (*it)->getclientID() << setw(15) << phonenumber
			 << address << endl << endl;

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
	cout << "                                            �ֹ����� �˻�                             " << endl;
	cout << LINE << endl;
	cout << "1. �� ID �˻� 2. ��ǰ�ڵ� �˻� ";

	num = ssearach_menu();		// �˻� �޴� �Է� ����ó��

	switch (num) {
	case 1:
		cout << "�˻��� �� ID�� �Է��ϼ��� : ";
		cin >> input;
		
		system("cls");
		cout << LINE << endl;
		cout << "                                             �� ID �˻����                             " << endl;
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
		cout << "                                            ��ǰ �ڵ� �˻����                             " << endl;
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