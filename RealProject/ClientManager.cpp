#include "Client.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ClientManager {
public:
	void add_Client()
	{
		string name;
		string clientid;
		string phonenumber;
		string address;

		cout << "�̸� : "; cin >> name;
		cout << "����� ID : "; cin >> clientid;
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		cout << "�ּ� : "; cin.ignore(); getline(cin, address);
		
		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()
	{
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout << "�̸� : " << c->getName() << endl
				<< "�� ID : " << c->getclientID() << endl
				<< "��ȭ��ȣ :" << c->getPhoneNumber() << endl
				<< "�ּ� : " << c->getAddress() << endl;
			});
	}

	void search_client()
	{
		string search;

		cout << "�˻� : "; cin >> search;
		
		auto it = find(clientList.begin(), clientList.end(), search);
		if (it == clientList.end()) {
			cout << search << "�Է��Ͻ� ������ ã�� �� �����ϴ�.\n";
		}

	}

private:
	vector<Client*>clientList;
};