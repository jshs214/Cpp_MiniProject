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

		cout << "�̸� : "; cin >> name;
		cout << "�� ID(PK) : "; cin >> clientid;
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		cout << "�ּ� : "; cin.ignore(); getline(cin, address);

		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()		//��ȸ
	{
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< "�̸� : " << c->getName() << endl
				<< "�� ID(PK): " << c->getclientID() << endl
				<< "��ȭ��ȣ :" << c->getPhoneNumber() << endl
				<< "�ּ� : " << c->getAddress() << endl;
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
				cout << "===========�˻����==========" << endl
					<< "�̸� : " << (*it)->getName() << endl
					<< "�� ID(PK): " << (*it)->getclientID() << endl
					<< "��ȭ��ȣ :" << (*it)->getPhoneNumber() << endl
					<< "�ּ� : " << (*it)->getAddress() << endl;
			}
			else
			{
				cout << "Ž�� x"<< endl;
			}
		}
	}

	void delete_client()		//����
	{
		string input;
		cout << "������ �� �̸� : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();

			if (sch_name == input) {
				clientList.erase(it);
				cout << input <<"������ �����Ǿ����ϴ�." << endl;
				break;
			}

			else
			{
				cout << "Ž�� x" << endl;
			}
		}
	}

private:
	vector<Client*>clientList;
};