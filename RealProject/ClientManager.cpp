#include "ClientManager.h"

#include <vector>
#include <algorithm>

int csearach_menu();	//�˻� ���ܰ� �Է� ó��
int cupdate_menu();	//���� ���ܰ� �Է� ó��

ClientManager::ClientManager()
{
	cout << "ClientManager ������"<<endl ;


	Sleep(1000);
}
ClientManager::~ClientManager()
{
	cout << "ClientManager �Ҹ���"<<endl;
	Sleep(1000);
}

vector<Client*>& ClientManager::getClientList()
{
	return clientList;
}

void ClientManager::add_Client()		// �� �߰�
{
	string name;		// �Է��� �� ��
	string clientid;	// id
	string phonenumber;	// ��ȭ��ȣ
	string address;		// �ּ� �߰��� ���� ��������

	system("cls");
	cout << LINE << endl;
	cout << "                           �ű� �� �������                             " << endl;
	cout << LINE << endl;

	cout << "�̸� : "; cin >> name;
	cout << "�� ID(PK) : "; cin >> clientid;
	cout << "��ȭ��ȣ (-���о��� �Է�) : "; cin >> phonenumber;
	cout << "�ּ� : "; cin.ignore(); getline(cin, address);

	while (1) {
		bool flag = false;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_PK = (*it)->getclientID();
			if (sch_PK == clientid) {
				flag = true;
				break;
			}
		}
		if (flag == false)	break;
		else
		{
			cout << " �ߺ� id �Դϴ�. �ٽ� �Է��� �ּ��� : ";
			cin >> clientid;
		}
	}

	Client* newClient = new Client(name, clientid, phonenumber, address);
	clientList.push_back(newClient);

	cout << "[�ű԰� ��� �Ϸ�]" << endl;

	Sleep(1000);	//Delay 1��
}// void ClientManager::add_Client()		// �� �߰��Լ� ����

void ClientManager::client_print()		//��ȸ
{

	system("cls");
	cout << LINE << endl;
	cout << "                               ��������ȸ                             " << endl;
	cout << LINE << endl;
	cout << "       �̸�     /   �� ID (PK)   /     ��ȭ��ȣ      /       �ּ�" << endl;
	cout << LINE << endl;

	for_each(clientList.begin(), clientList.end(), [](Client* c) {
		cout << c->getName() << " / "
			<< c->getclientID() << " / "
			<< c->getPhoneNumber() << " / "
			<< c->getAddress() << endl;
		});

	cout << "[������ ��ȸ �Ϸ�]" << endl;
	cout << LINE << endl;
	cout << "[�� " << clientList.size() << "���� ������ �ֽ��ϴ�]" << endl;
	cout << LINE << endl;
}// void ClientManager::client_print()		// �� ��ȸ�Լ� ����

void ClientManager::search_client()		//�˻�
{
	bool flag = false;
	int num = 0;
	string input;	//�˻� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	system("cls");
	cout << LINE << endl;
	cout << "                             ���� �˻�                             " << endl;
	cout << LINE << endl;
	cout << "1. ���� �˻� 2. �� ID �˻� "; //cin >> num;
	
	num=csearach_menu();
	switch (num)
	{
	case 1:
		cout << "���� �˻� : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                             ������ �˻����                             " << endl;
		cout << LINE << endl;
		cout << "       �̸�     /   �� ID (PK)   /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << LINE << endl;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name.find(input) != -1) {
				flag = true;
				cout << (*it)->getName() << " / "
					<< (*it)->getclientID() << " / "
					<< (*it)->getPhoneNumber() << " / "
					<< (*it)->getAddress() << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� ������ �����ϴ�]" << endl;
		cout << LINE << endl;
		break;		// case 1 break;

	case 2:
		cout << "�� ID : "; cin >> input;

		system("cls");
		cout << LINE << endl;
		cout << "                             ������ �˻����                             " << endl;
		cout << LINE << endl;
		cout << "       �̸�     /   �� ID (PK)   /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << LINE << endl;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_id = (*it)->getclientID();
			if (sch_id.find(input) != -1) {
				flag = true;
				cout << (*it)->getName() << " / "
					<< (*it)->getclientID() << " / "
					<< (*it)->getPhoneNumber() << " / "
					<< (*it)->getAddress() << endl;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �� ID�� �����ϴ�]" << endl;
		cout << LINE << endl;
		break;		// case 2 break;
	}

}// void ClientManager::search_client()		//�˻��Լ� ����


void ClientManager::delete_client()		//����
{
	bool flag = false;
	string input;	//���� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	system("cls");

	cout << LINE << endl;
	cout << "                             �� ���� ����                              " << endl;
	cout << LINE << endl;

	
	cout << "������ �� ID �Է��ϼ��� : "; cin >> input;

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		auto sch_ID = (*it)->getclientID();
		if (sch_ID == input) {
			flag = true;
			clientList.erase(it);
			cout << input << " �� ���� ������ �����Ǿ����ϴ�." << endl;
			cout << "[������ ���� �Ϸ�]" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "[�Է��Ͻ� �� ID�� �����ϴ�]" << endl;
	cout << LINE << endl;
}// void ClientManager::delete_client()		//�����Լ� ����

void ClientManager::update_client()	//���� ����
{
	int num = 0;
	bool flag = false;
	string up_data;	// ������Ʈ �� ���� �� ������
	string up_phonenumber;
	string input;	//���� �� ������ �����Ϳ� ��Ī�ϱ� ���� �Է¹޴� ��������
	system("cls");
	cout << LINE << endl;
	cout << "                             �� ���� ����                              " << endl;
	cout << LINE << endl;

	cout << "�� ID �Է� : "; cin >> input;

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		auto sch_name = (*it)->getclientID();		//�Է��� �� ID �����Ͱ� ������

		if (sch_name == input) {
			flag = true;
			cout << "1. �̸� ����  2. ��ȭ��ȣ ���� 3. �ּ� ����" << endl;		//cin >> num;	//������ ����
			num = cupdate_menu();
			switch (num)
			{
			case 1:		//�̸� ����
				cout << "������ �̸� �Է�" << endl;		cin >> up_data;
				(*it)->setName(up_data);
				cout << "[�̸� ���� �Ϸ�]" << endl;
				break;

			case 2:		//��ȭ��ȣ ����
				cout << "������ ��ȭ��ȣ �Է�" << endl;	cin >> up_phonenumber;
				(*it)->setPhoneNumber(up_phonenumber);
				cout << "[��ȭ��ȣ ���� �Ϸ�]" << endl;
				break;

			case 3:		//�ּ� ����
				cout << "������ �ּ� �Է� : ";	cin >> up_data;
				(*it)->setAddress(up_data);
				cout << "[�ּ� ���� �Ϸ�]" << endl;
				break;
			}
		}
		if (flag == false)
			cout << "[�Է��Ͻ� �� ID�� �����ϴ�]" << endl;

		cout << LINE << endl;
	}
}// void ClientManager::update_client()	//���� ����

int csearach_menu()		// �˻� �޴� �Է� ����ó��
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu �� ���ڸ� �Է� �޵���
		cout << "[�޴� ��ȣ�� �Է����ּ���]"<<endl;
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
int cupdate_menu()	// ���� �޴� �Է� ���� ó��
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
