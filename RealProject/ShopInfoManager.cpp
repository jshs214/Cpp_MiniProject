#define _CRT_SECURE_NO_WARNINGS
#include "ShopInfoManager.h"

#include<iostream>
#include <vector>
#include <algorithm>
#include<fstream>
#include<sstream>
#include <iomanip>
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
				int shopkey = atoi(row[0].c_str());		// ����������� ���� int��  ����ȯ
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
	cout << "ShopInfo.txt�� �ε��Ͽ����ϴ�." << endl;
	Sleep(1000);
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
	cout << "ShopInfo.txt�� �����߽��ϴ�." << endl;
	Sleep(1000);
	fs.close();
}

void ShopInfoManager::ShopMainMenu()	//ShopInfo ȭ��
{
	int shoping_menu;	// 1. �ֹ� 2. ��ȸ 3. �˻� 4. ���� 5. ����
	int back = 0;
	shoping_menu = smenu();	//���������޴����� 1 ~ 5�� �޴� �Լ�
	switch (shoping_menu)
	{
	case 1:		// �ֹ�
		add_Shoplist();
		break;
	case 2:		//�ֹ����� ��ȸ
		shoplist_print();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	case 3:		//�ֹ����� �˻�
		search_shoplist();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	case 4:		//�ֹ����� ����
		update_shop();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	case 5:		// �ֹ� ���� ����
		delete_shoplist();
		cout << "���� (0) "; cin >> back;
		if (back == 0)break;
	}
}
void ShopInfoManager::add_Shoplist()       // ShopInfolist���Ϳ� �����͸� push_back �ϴ� �ֹ� �Լ�
{
	int shopkey=1000, stock = 0,price =0;
	string productid, productname, producttype, name, clientid, phonenumber, address;

	string cid, pid;	// �Է¹��� ClientID�� ProductID ����
	int up_stock;
	int cinput = 0, pinput=0, sinput=0; // �� Ŭ���� PKŰ�� �ִ��� �˻��ϱ� ���� ����

	time_t timer;			// �ð��� ���� ����
	struct tm* t;
	timer = time(NULL); // 1970�� 1�� 1�� 0�� 0�� 0�ʺ��� �����Ͽ� ��������� ��
	t = localtime(&timer); 
	int tm_year, tm_mon, tm_mday;
	tm_year = t->tm_year + 1900;	tm_mon = t->tm_mon + 1;	tm_mday = t->tm_mday;	// ��, ��, ��

	bool cflag = false, pflag=false;	//���˻縦���� ����
	
	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ�                             " << endl;
	cout << LINE << endl;

	cout << "�� ID : "; cin >> cid;
	cout << "��ǰ ID : "; cin >> pid;
	cout << "������ ��ǰ ���� : "; cin >> stock;

	while (1) {					//Client ID �ߺ��˻� ( ���ƾ� ���� )
		cflag = false;
		cinput = 0;
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
		else  //������ ClientID ���Է�
		{
			cout << "�� ID�� �����ϴ�. ���Է� ���ּ��� (���� 0) : ";
			cin >> cid;	
		}

		if (cid == "0")    return;		//��������
	}

	while (1) {					//Product ID �ߺ��˻� ( ���ƾ� ���� )
		pflag = false;
		pinput = 0;
		for (auto it = PM.getproductList().begin(); it != PM.getproductList().end(); ++it)
		{
			auto sch_pid = (*it)->getProductID();
			if (sch_pid == pid) {           // ProductID�� �Է��� id�� ������
				pflag = true;
				pinput++;
				break;
			}
		}
		if (pflag == true)	break;
		else  //������ ProductID ���Է�
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
	
	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //�ֹ����� PKŰ �ߺ��˻�
	{
		auto sch_shopkey = (*it)->getShopkey();
		if (sch_shopkey == shopkey) {		//Ű���� ������ 1 ����
			shopkey++;
		}
	}
	
	for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {				// �ֹ� �� �� Product ������ ��� ������ ����
		auto id = (*pit)->getProductID();
		if (pid == id) {			// �Է��� pid�� Product ������ ID ������ Product ������ ��� ����
			while (1) {
				sinput = 0;// �ֹ��������� ��� ������ üũ
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
	
	if (cinput > 0 && pinput > 0&& sinput > 0) {			// Client, Product�� ���������� �����ǰ�, ��� �������̸� �ֹ�.
		ShopInfo* newShopC = new ShopInfo(shopkey, productid, productname, producttype,	
											price, stock, name, clientid, phonenumber, address,tm_year,tm_mon,tm_mday);
		ShopInfolist.push_back(newShopC);
	}
	Sleep(1000);
}

void ShopInfoManager::shoplist_print()     // ShopInfolist ���� ��ȸ
{
	int sum = 0;

	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ����� ������ȸ" << endl;
	cout << LINE << endl;

	print_Shopmenu();		//�ֹ����� �����θ޴� ���

	sort(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* a, ShopInfo* b) {		//�ֹ���ȣ ,��¥ �������� ����	
		if (a->getyear() == b->getyear() && a->getmonth() == b->getmonth() && a->getday() == b->getday()) {	// ��¥�� ������ �ֹ���ȣ key������ ��������
			return a->getShopkey() < b->getShopkey();
		}
		else if (a->getyear() == b->getyear()) {	//��¥�� �ٸ��� ��¥�� ��������
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
		showShoplist(*it); //Shoplist ���� ��� �Լ�
	}

	cout << "[�ֹ����� ��ȸ �Ϸ�]" << endl;
	cout << LINE << endl;
	cout << "[�� " << ShopInfolist.size() << "���� �ֹ��� �ֽ��ϴ�.]" << endl;
	cout << LINE << endl;
}

void ShopInfoManager::search_shoplist()    // ShopInfolist �˻�
{
	int price, sum = 0;
	string name, phonenumber, address, productname, producttype; 
	string input;	//�˻� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������

	int num = 0;	//� ������ �˻����� switch case ����
	bool flag = false;

	system("cls");
	cout << LINE << endl;
	cout << "                                            �ֹ����� �˻�" << endl;
	cout << LINE << endl;
	cout << "1. �� ID �˻� 2. ��ǰ�ڵ� �˻� ";

	num = ssearach_menu();		// �˻� �޴� �Է� ����ó��
	switch (num) {
	case 1:
		cout << "�˻��� �� ID�� �Է��ϼ��� : ";
		cin >> input;	// Client���Ϳ� �ִ� ID�� ���ϱ� ���� ����
		
		system("cls");
		cout << LINE << endl;
		cout << "                                       [�Է��� �� ID : "<<input<<" �˻����]"  << endl;
		cout << LINE << endl;
		print_Shopmenu();		//�ֹ����� �����θ޴� ���

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it) 
		{
			if ((*it)->getclientID().find(input) != -1)		// �Է��� input ���ڿ��� ShopInfolist������ clientID�� ���ԵǸ� ����.
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if ((*cit)->getclientID().find(input) != -1) {// �Է��� ���ڿ��� ShopInfolist������ ClientID�� ���ԵǸ�
						flag = true;
						if (c_ID == (*cit)->getclientID()) {	// Client ���Ͱ� ����Ű�� ������ ������
							name = (*cit)->getName();
							phonenumber = (*cit)->getPhoneNumber();
							address = (*cit)->getAddress();
						}
					}
				}
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if (p_ID == (*pit)->getProductID()) {		// Product ���Ͱ� ����Ű�� ������ ������
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
		cin >> input;	// Product���Ϳ� �ִ� ID�� ���ϱ� ���� ����

		system("cls");
		cout << LINE << endl;
		cout << "                                       [�Է��� ��ǰ�ڵ� : " << input << " �˻����]" << endl;
		cout << LINE << endl;
		print_Shopmenu();		//�ֹ����� ������ �޴�

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getProductID().find(input) != -1)	// �Է��� ���ڿ��� ShopInfolist������ ProductID�� ���ԵǸ�
			{
				string p_ID = (*it)->getProductID();
				string c_ID = (*it)->getclientID();	
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit)
				{
					if ((*pit)->getProductID().find(input) != -1) {	// �Է��� ���ڿ��� Product������ ID�� ���ԵǸ�
						flag = true;
						if (p_ID == (*pit)->getProductID()) {	// Product ���Ͱ� ����Ű�� ������ ������
							productname = (*pit)->getProductName();
							producttype = (*pit)->getProductType();
							price = (*pit)->getPrice();
							sum = price * (*it)->getStock();
						}
					}
				}
				for (auto cit = CM.getClientList().begin(); cit != CM.getClientList().end(); ++cit)
				{
					if (c_ID == (*cit)->getclientID()) {		// Client ���Ͱ� ����Ű�� ������ ������
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
		break;	//case2 ����.
	case 3: 		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		Sleep(1000); break;
	}
}//�˻��ϱ� �Լ� ����

void ShopInfoManager::update_shop()	//�ֹ����� ���� �Լ�
{
	int input;
	int up_stock;	// ���� �� ������Ʈ�� ���� ����
	string up_data;	// ���� �� ������Ʈ�� �ּ�, ����ó ����
	int num;	//� ������ �˻����� switch case ����
	bool flag = false;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� ���
	{
			showShoplist(*it);
	}
	cout << LINE << endl;
	cout << " 1. �����, 2. ������ ����ó ���� 3. ����� ���� ";

	num=ssearach_menu();	// 1,2,3 �ܿ� �Է� ���� ó��
	switch (num) {
	case 1:	// �����
		cout << "������� �ֹ���ȣ�� �Է��ϼ��� : "; cin >> input;

		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PKŰ�� �Է°��� ������ ��� ���� ����
				flag = true;
				for (auto pit = PM.getproductList().begin(); pit != PM.getproductList().end(); ++pit) {
					auto sid = (*it)->getProductID();
					auto pid = (*pit)->getProductID();
					if (sid == pid) {	//������ ShopInfo�� ��ǰ�ڵ带 Product���ִ� ��ǰ�ڵ�� ��Ī
						cout << "���� ���� �Է� : ";	cin >> up_stock;

						if (up_stock <= 0) {
							cout << "[���� ������ 0���� ���ų� �۽��ϴ�]" << endl;
						}
						else {
							if (up_stock > (*pit)->getStock() + (*it)->getStock()) {	// ������ ������ Product�� ��� + ���� �ֹ���� ���� ũ��
								cout << "[���� ����� �ֹ��Ͻ� ������ �� �����ϴ�. " 
									<<"���氡�� �ִ� ���� : "<<(*pit)->getStock() + (*it)->getStock() <<"]" << endl;
							}
							else {
								int stock = (*pit)->getStock() + (*it)->getStock();		// ��� ���� �� ��ǰ�� ��� + ���� �ֹ����� ���� ����
								(*pit)->setStock(stock);		//product�� �ִ� ��� ������ ���
								(*it)->setStock(up_stock);		//Shoplist �ֹ��������� ����

								int up_stock = (*pit)->getStock() - (*it)->getStock();	// ��ǰ��� - ������ �ֹ����� 
								(*pit)->setStock(up_stock);
								cout << "[������ ����Ǿ����ϴ�.]" << endl;
							}
							break;
						}
					}
				}
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �ֹ���ȣ�� �����ϴ�]" << endl;
		break;
	case 2:	// ����ó����
		cout << "������ ����ó ������ �ֹ���ȣ�� �Է��ϼ��� : "; cin >> input;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PKŰ�� �Է°��� ������ ��ȭ��ȣ ���� ����
				flag = true;
				cout << "������ ������ ����ó �Է� : "; cin >> up_data;
				(*it)->setphoneNumber(up_data);
				cout << endl << "[������ ����ó�� ����Ǿ����ϴ�.]" << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �ֹ���ȣ�� �����ϴ�]" << endl;
		break;
	case 3:	// ������ּ� ����
		cout << "������ ����� ������ �ּҸ� �Է��ϼ��� : "; cin >> input;
		for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
		{
			if ((*it)->getShopkey() == input) {		//ShopInfo PKŰ�� �Է°��� ������ �ּ� ���浿��
				flag = true;
				cout << "������ ����� ���Է� : "; cin.ignore(); getline(cin, up_data);
				(*it)->setaddress(up_data);
				cout << endl << "[������� ����Ǿ����ϴ�.]" << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �ֹ���ȣ�� �����ϴ�]" << endl;
		break;	//case 3 ����
	}
}	//�ֹ����� ���� �Լ� ����
void ShopInfoManager::delete_shoplist() {	//���� �Լ�
	int input;
	bool flag = false;
	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� ���
	{
		showShoplist(*it);
	}
	cout << LINE << endl;
	cout << "������ �ֹ���ȣ �Է��ϼ��� : "; cin >> input;

	for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
	{
		auto sch_ID = (*it)->getShopkey();
		if (sch_ID == input) {	// ShopInfolist�� �ֹ���ȣ Ű�� �Է°��� ������ �ֹ����� ���� ����
			flag = true;
			ShopInfolist.erase(it);
			cout << input << " �� ���� �ֹ������� �����Ǿ����ϴ�." << endl;
			cout << "[�ֹ����� ���� �Ϸ�]" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "[�Է��Ͻ� �ֹ���ȣ�� �����ϴ�]" << endl;
	cout << LINE << endl;
}
void ShopInfoManager::showShoplist(ShopInfo* shopinfo)		//ShopInfolist ��� ���ִ� �Լ�
{
	int sum = 0;
	sum = shopinfo->getPrice() * shopinfo->getStock();
	cout.setf(ios::left); //���� ����
	cout << " #" << setw(27) << shopinfo->getShopkey() << setw(15) << shopinfo->getProductID() << setw(15) << shopinfo->getproductName() << setw(15)
		<< shopinfo->getproductType() << setw(11) << shopinfo->getPrice()
		<< setw(11) << shopinfo->getStock() << setw(15) << sum << endl;
	cout << "  " << shopinfo->getyear() << "." << shopinfo->getmonth() << "." << setw(10) << shopinfo->getday() << setw(10) <<
		shopinfo->getname() << setw(15) << shopinfo->getclientID() << setw(15) << shopinfo->getphoneNumber()
		<< shopinfo->getaddress() << endl << endl;
}

int ShopInfoManager::smenu()	// �޴����� ������ ������ �޵���
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
int ShopInfoManager::ssearach_menu() // �޴����� ������ ������ �޵���
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu �� ���ڸ� �Է� �޵���
		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 4)
		return menu;
	else {
		cout << "[�޴� ��ȣ�� �Է����ּ���]" << endl;
		Sleep(1000);
	}
	return 0;
}

void ShopInfoManager::print_Shopmenu()		//�ֹ����� �����θ޴� ���
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