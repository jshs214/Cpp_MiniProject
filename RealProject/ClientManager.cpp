#include "Client.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ClientManager {
public:
	void add_Client()		// �Է�
	{
		string name;
		string clientid;
		string phonenumber;
		string address;

		system("cls");
		cout << " [�ű� �� ���� �Է�]" << endl;
		cout << "�̸� : "; cin >> name;
		cout << "�� ID(PK) : "; cin >> clientid;
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		cout << "�ּ� : "; cin.ignore(); getline(cin, address);

		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()		//��ȸ
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                               ��������ȸ                             " << endl;
		cout << "========================================================================" << endl;
		cout << "       �̸�      /     �� ID     /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << "========================================================================" << endl;
	
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< c->getName() << " / "
				<< c->getclientID() << " / "
				<<  c->getPhoneNumber() << " / "
				<<  c->getAddress() << endl;
			});
	}

	void search_client()		//�˻�
	{
		string input;

		cout << "�˻� : "; cin >> input;

		for(auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name == input) {
				cout << "========================================================================" << endl;
				cout << "                               �˻����                             " << endl;
				cout << "========================================================================" << endl;
				cout << "       �̸�      /     �� ID     /     ��ȭ��ȣ      /       �ּ�" << endl;
				cout << "========================================================================" << endl;
				cout << "�̸� : " << (*it)->getName() << endl
					<< "�� ID(PK): " << (*it)->getclientID() << endl
					<< "��ȭ��ȣ :" << (*it)->getPhoneNumber() << endl
					<< "�ּ� : " << (*it)->getAddress() << endl;
			}
			else if(it == clientList.end())
			{
					cout << "Ž�� ����";
			}
		}
	}

	void delete_client()		//���� �� ID�� pkŰ��
	{
		string input;
		cout << "������ ���� �Է��ϼ��� : "; cin >> input;		// ���� -> �� ID�� �����ؾ���

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();

			if (sch_name == input) {
				clientList.erase(it);
				cout << input <<"������ �����Ǿ����ϴ�." << endl;
				break;
			}

			
		}
	}

	void update_client()	//�� ����
	{
		string input;
		int up_num;
		string up_data;

		cout << "���� ���� �� ���� : "; cin >> input;		// �� ID�� �����ؾ���

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();		//�Է��� ���� �����Ͱ� ������

			if (sch_name == input) {
				cout << "1. �̸� ����  2. ��ȭ��ȣ ���� 3. �ּ� ����" << endl;
				cin >> up_num;
				switch (up_num)
				{
				case 1:		//�̸� ����
					cout << "������ �̸� �Է�"<<endl;		cin >> up_data;
					(*it)->setName(up_data);
					break;

				case 2:		//��ȭ��ȣ ����
					cout << "������ ��ȭ��ȣ �Է�" << endl;	cin >> up_data;
					(*it)->setPhoneNumber(up_data);
					break;

				case 3:		//�ּ� ����
					cout << "������ �ּ� �Է� : " ;	cin >> up_data;
					(*it)->setAddress(up_data);
					break;
				}
			}

			/*else
			{
				cout << "Ž�� ����";
			}*/
		}
	}

private:
	vector<Client*>clientList;
};