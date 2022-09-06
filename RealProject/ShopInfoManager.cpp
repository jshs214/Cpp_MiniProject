#define _CRT_SECURE_NO_WARNINGS
#include "ShopInfoManager.h"

#include <vector>
#include <algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include <iomanip>	//setw
#include <ctime>


ShopInfoManager::ShopInfoManager(ClientManager& cm,ProductManager& pm)		//ShopInfoManager �����ڿ��� ���� load
	:CM(cm), PM(pm)
{
	ifstream file;
	file.open("ShopInfo.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {
				int shopkey = atoi(row[0].c_str());		// int�� ShopInfo�� PKŰ ����ȯ
				int price = atoi(row[4].c_str());		// int�� ���� ����ȯ
				int stock = atoi(row[5].c_str());		// int�� ���� ����ȯ
				int year = atoi(row[10].c_str());
				int month = atoi(row[11].c_str());
				int day = atoi(row[12].c_str());
				ShopInfo* s = new ShopInfo(shopkey, row[1], row[2], row[3], price, stock, 
											row[6], row[7], row[8], row[9],year,month,day);
				ShopInfolist.push_back(s);
			}
		}
	}
	file.close();
}

ShopInfoManager::~ShopInfoManager()			//ShopInfoManager �Ҹ��ڿ��� ���� �Է�
{
	ofstream fs("ShopInfo.txt");
	if (!fs) {
		cout << "����� ������ �� �� �����ϴ�.";
		Sleep(1000);
	}

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
	{
		fs << (*it)->getShopkey() << ", " << (*it)->getProductID() << ", " << (*it)->getproductName() << ", " 
			<< (*it)->getproductType() << ", " << (*it)->getPrice() << ", " << (*it)->getStock() << ", "
			<< (*it)->getname() << ", " << (*it)->getclientID() << ", " << (*it)->getphoneNumber() << ", "
			<<(*it)->getaddress() << ", " << (*it)->getyear() << ", " << (*it)->getmonth() << ", " << (*it)->getday()  << ", " <<endl;
	}
	fs.close();
}

void ShopInfoManager::ShopMainMenu()
{
	int shoping_menu;
	int back = 0;
	shoping_menu = smenu();	//���������޴����� ������ ������ �޵���
	switch (shoping_menu)
	{
	case 1:		// �ֹ�
		add_Shoplist();
		break;
	case 2:		//�ֹ� ���� ��ȸ
		shoplist_print();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	case 3:		//�ֹ� ���� �˻�
		search_shoplist();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	}
}
void ShopInfoManager::add_Shoplist()       // �ֹ��ϱ�
{
	int shopkey=1000, stock = 0,price =0;	//ShopInfo�� PKŰ 1000���� ���� , �ֹ� �� ����, ����
	string cid, pid;	// �Է¹��� ClientID�� ProductID ����
	int up_stock;	// ���ݿ��� �ʿ��� ����
	int cinput = 0, pinput=0, sinput=0; //��ġ�ϴ��� flag
	string productid, productname, producttype, name, clientid, phonenumber, address;
	
	time_t timer;			// �ð��� ���� ����
	struct tm* t;
	timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
	t = localtime(&timer); // �������� ���� ����ü�� �ֱ�
	int tm_year, tm_mon, tm_mday;
	tm_year = t->tm_year + 1900;	tm_mon = t->tm_mon + 1;	tm_mday = t->tm_mday;	// ��, ��, ��
	bool cflag = false, pflag=false;	//���˻縦���� ����
	
	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ�                             " << endl;
	cout << LINE << endl;


	cout << "�� ID : "; cin >> cid;   // ClientID PK�˻縦 ���� cin
	cout << "��ǰ ID : "; cin >> pid;   // ProductID PK�˻縦 ���� pin
	cout << "������ ��ǰ ���� : "; cin >> stock;

	while (1) {					//Client ID �ߺ��˻� ( ���ƾ� ���� )
		cflag = false;
		cinput = 0;// ClientID�� ���������� �����Ǹ� 1, �ƴϸ� 0
		for (auto it =CM.getClientList().begin(); it != CM.getClientList().end(); ++it)
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

		if (cid == "0")    return;		//��������
	}

	while (1) {					//Product ID �ߺ��˻� ( ���ƾ� ���� )
		pflag = false;
		pinput = 0;	// ProductID�� ���������� �����Ǹ� 1, �ƴϸ� 0
		for (auto it = PM.getproductList().begin(); it != PM.getproductList().end(); ++it)
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
		if (pid == "0") return;		//��������
		}

		for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)		// Client�� �����͸� ShopInfolist ���Ϳ� ������
		{
			auto sch_cid = (*cit)->getclientID();
			if (sch_cid == cid) {           
				name = (*cit)->getName();
				clientid = (*cit)->getclientID();
				phonenumber = (*cit)->getPhoneNumber();
				address = (*cit)->getAddress();
			}
		}

		for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)		// Product�� �����͸� ShopInfolist ���Ϳ� ������
		{
			auto sch_PK = (*pit)->getProductID();
			if (sch_PK == pid) {
				productid = (*pit)->getProductID();
				productname = (*pit)->getProductName();
				price = (*pit)->getPrice();
				producttype = (*pit)->getProductType();
			}
		}
	

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //�ֹ����� PK �ߺ��˻�
	{
		auto sch_shopkey = (*it)->getShopkey();
		if (sch_shopkey == shopkey) {
			shopkey++;
		}
	}
	
	for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {				// �ֹ� �� �� Product�� ��� ������ ����
		auto id = (*pit)->getProductID();	////Product�� �ִ� ��ID
		if (pid == id) {			//pid�� �ֹ� �� �� �Է��� �� id
			while (1) {
				sinput = 0;// �ֹ��������� ��� ������ 1, �ƴϸ� 0

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
		ShopInfo* newShopC = new ShopInfo(shopkey, productid, productname, producttype, 
											price, stock, name, clientid, phonenumber, address,tm_year,tm_mon,tm_mday);
		ShopInfolist.push_back(newShopC);
	}
	Sleep(1000);	//Delay 1��
}// �ֹ��ϱ� �Լ� ����


void ShopInfoManager::shoplist_print()     // ��ȸ
{
	int sum = 0;   //����

	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ����� ������ȸ                             " << endl;
	cout << LINE << endl;

	print_Shopmenu();		//�ֹ����� ���̺� �޴�

	sort(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* a, ShopInfo* b) {		//�ֹ���ȣ �������� ����
		return a->getShopkey() < b->getShopkey();
		});

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� ���
	{
		showShoplist(*it);
	}

	cout << "[�ֹ����� ��ȸ �Ϸ�]" << endl;
	cout << LINE << endl;
	cout << "[�� " << ShopInfolist.size() << "���� �ֹ��� �ֽ��ϴ�.]" << endl;
	cout << LINE << endl;
}// ��ȸ�ϱ� �Լ� ����

void ShopInfoManager::search_shoplist()    //�˻�
{
	string name, phonenumber, address, productname, producttype;            //Client ����, ��ȭ��ȣ, �ּ�, ��ǰ��, ��ǰ����
	string input;	//�˻� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	int price;           //  ��ǰ ����
	int sum = 0;   //����


	bool flag = false;
	int num = 0;	//� ������ �˻����� switch case ����

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
		cout << "                                       [�Է��� �� ID : "<<input<<" �˻����]"  << endl;
		cout << LINE << endl;
		print_Shopmenu();		//�ֹ����� ���̺� �޴�

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
		{
			if ((*it)->getclientID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
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
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if (p_ID == (*pit)->getProductID()) {
						productname = (*pit)->getProductName();
						producttype = (*pit)->getProductType();
						price = (*pit)->getPrice();
						sum = price * (*it)->getStock();
					}
				}
				showShoplist(*it);	//ShopInfolist ���� ���
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �� ID���� �ֹ��� �����ϴ�]" << endl;
		cout << LINE << endl;

		break;  //case 1 ����

	case 2:
		cout << "�˻��� ��ǰ�ڵ带 �Է��ϼ��� : ";
		cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                                       [�Է��� ��ǰ�ڵ� : " << input << " �˻����]" << endl;
		cout << LINE << endl;
		print_Shopmenu();		//�ֹ����� ���̺� �޴�

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
		{
			if ((*it)->getProductID().find(input) != -1)
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
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
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if (c_ID == (*cit)->getclientID()) {
						name = (*cit)->getName();
						phonenumber = (*cit)->getPhoneNumber();
						address = (*cit)->getAddress();
					}
				}

				showShoplist(*it);	//ShopInfolist ���� ���
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� ��ǰ�ڵ� ���� �ֹ��� �����ϴ�]" << endl;
		cout << LINE << endl;
		break;
	}
}//�˻��ϱ� �Լ� ����

void ShopInfoManager::showShoplist(ShopInfo* shopinfo)		//ShopInfolist ���
{
	int sum = 0;
	sum = shopinfo->getPrice() * shopinfo->getStock();
	cout.setf(ios::left); //���� ���� �� ���
	cout << " #" << setw(27) << shopinfo->getShopkey() << setw(15) << shopinfo->getProductID() << setw(15) << shopinfo->getproductName() << setw(15)
		<< shopinfo->getproductType() << setw(11) << shopinfo->getPrice()
		<< setw(11) << shopinfo->getStock() << setw(15) << sum << endl;
	cout << "  " << shopinfo->getyear() << "." << shopinfo->getmonth() << "." << setw(10) << shopinfo->getday() << setw(10) <<
		shopinfo->getname() << setw(15) << shopinfo->getclientID() << setw(15) << shopinfo->getphoneNumber()
		<< shopinfo->getaddress() << endl << endl;
}

int ShopInfoManager::smenu()	// �������� �޴����� ������ ������ �޵���
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu �� ���ڸ� �Է� �޵���
		cout << "[�޴� ��ȣ�� �Է����ּ���]";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu >= 0 && menu < 6)
		return menu;
	else {
		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		Sleep(1000);
	}
	return 0;
}
int ShopInfoManager::ssearach_menu()		// �˻� �޴� �Է� ����ó��
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

void ShopInfoManager::print_Shopmenu()		//�ֹ����� ���̺� �޴�
{
	cout.setf(ios::left); //���� ���� �� ���
	cout << setw(29) << " �ֹ���ȣ(PK)" << setw(15) << "��ǰ�ڵ�" << setw(15) << "��ǰ��" << setw(15) << "��ǰ����" << setw(11) << "����"
		<< setw(11) << "�ֹ�����" << setw(11) << "�ֹ�����" << endl;
	cout << setw(19) << "  ��¥"<<setw(10) << "����" << setw(15) << "��ID" << setw(15) << "��ȭ��ȣ" << "�ּ�" << endl;
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