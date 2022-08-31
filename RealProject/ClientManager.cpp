#include "Client.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include "Line.h"
class ClientManager {
public:
	void add_Client()		// �Է�
	{
		string name;
		string clientid;
		string phonenumber;
		string address;

		system("cls");
		cout << LINE << endl;
		cout << "                           �ű� �� �������                             " << endl;
		cout << LINE << endl;

		cout << "�̸� : "; cin >> name;
		cout << "�� ID(PK) : "; cin >> clientid;
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		cout << "�ּ� : "; cin.ignore(); getline(cin, address);

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_PK = (*it)->getclientID();

			if (sch_PK == clientid) {
				while(1){
				cout << " �ߺ� id �Դϴ�. �ٽ� �Է��� �ּ��� : ";
				cin >> clientid;
					if (sch_PK != clientid)	break;
				}
			}
		}

		Client* newClient = new Client(name, clientid ,phonenumber, address);
		clientList.push_back(newClient);

		cout << "[�ű԰� ��� �Ϸ�]" << endl;

		Sleep(1000);	//Delay 1��
	}

	void add_client_print()		//��ȸ
	{

		system("cls");
		cout << LINE << endl;
		cout << "                               ��������ȸ                             " << endl;
		cout << LINE << endl;
		cout << "       �̸�     /   �� ID (PK)   /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << LINE << endl;

		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< c->getName() << " / "
				<< c->getclientID() << " / "
				<<  c->getPhoneNumber() << " / "
				<<  c->getAddress() << endl;
			});
		cout << "[������ ��ȸ �Ϸ�]" << endl;
		cout << LINE << endl;
	}

	void search_client()		//�˻�
	{
		string input;
		int sch_num;		//�˻��� ����
		bool flag = 0;

		system("cls");
		cout << LINE << endl;
		cout << "                             ���� �˻�                             " << endl;
		cout << LINE << endl;
		cout << "1. ���� �˻� 2. �� ID �˻� "; cin >> sch_num;

		switch (sch_num)
		{
		case 1:
			cout << "���� �˻� : "; cin >> input;
			for (auto it = clientList.begin(); it != clientList.end(); ++it)
			{
				auto sch_name = (*it)->getName();
				if (sch_name.find(input)!= -1) {
					flag = true;
					cout << (*it)->getName() << " / "
						<< (*it)->getclientID() << " / "
						<< (*it)->getPhoneNumber() << " / "
						<< (*it)->getAddress() << endl;
				}	
			}
			if (flag == false)
				cout << "�Է��Ͻ� ������ �����ϴ�" << endl;
			cout << LINE << endl;
			break;		// case 1 break;

		case 2:
			cout << "�� ID : "; cin >> input;
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
				cout << "�Է��Ͻ� ������ �����ϴ�" << endl;
			cout << LINE << endl;
			break;		// case 2 break;
		}
		

	}

	void delete_client()		//����
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             �� ���� ����                              " << endl;
		cout << LINE << endl;
		string input;
		bool flag = 0;
		cout << "������ �� ID �Է��ϼ��� : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_ID = (*it)->getclientID();
			if (sch_ID == input) {
				flag = true;
				clientList.erase(it);
				cout << input <<" �� ���� ������ �����Ǿ����ϴ�." << endl;
				cout << "[������ ���� �Ϸ�]" << endl;
				break;
			}
		}
		if (flag == false)
			cout << "�Է��Ͻ� �� ID�� �����ϴ�" << endl;
		cout << LINE << endl;
	}

	void update_client()	//���� ����
	{
		system("cls");
		cout << LINE << endl;
		cout << "                             �� ���� ����                              " << endl;
		cout << LINE << endl;
		string input;	//�� ID ����
		int up_num;	// ������Ʈ���� �������� ����
		string up_data;	// ������Ʈ �� ������
		bool flag = 0;
		cout << "�� ID �Է� : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getclientID();		//�Է��� �� ID �����Ͱ� ������

			if (sch_name == input) {
				flag = true;
				cout << "1. �̸� ����  2. ��ȭ��ȣ ���� 3. �ּ� ����" << endl;
				cin >> up_num;	//������ ����

				switch (up_num)
				{
				case 1:		//�̸� ����
					cout << "������ �̸� �Է�"<<endl;		cin >> up_data;
					(*it)->setName(up_data);
					cout << "[�̸� ���� �Ϸ�]" << endl;
					break;

				case 2:		//��ȭ��ȣ ����
					cout << "������ ��ȭ��ȣ �Է�" << endl;	cin >> up_data;
					(*it)->setPhoneNumber(up_data);
					cout << "[��ȭ��ȣ ���� �Ϸ�]" << endl;
					break;

				case 3:		//�ּ� ����
					cout << "������ �ּ� �Է� : " ;	cin >> up_data;
					(*it)->setAddress(up_data);
					cout << "[�ּ� ���� �Ϸ�]" << endl;
					break;
				}
			}
			if (flag == false)
				cout << "�Է��Ͻ� �� ID�� �����ϴ�" << endl;
			cout << LINE << endl;
		}
	}

private:
	vector<Client*>clientList;
};
