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

		cout << "이름 : "; cin >> name;
		cout << "사용자 ID : "; cin >> clientid;
		cout << "전화번호 : "; cin >> phonenumber;
		cout << "주소 : "; cin.ignore(); getline(cin, address);
		
		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()
	{
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout << "이름 : " << c->getName() << endl
				<< "고객 ID : " << c->getclientID() << endl
				<< "전화번호 :" << c->getPhoneNumber() << endl
				<< "주소 : " << c->getAddress() << endl;
			});
	}

	void search_client()
	{
		string search;

		cout << "검색 : "; cin >> search;
		
		auto it = find(clientList.begin(), clientList.end(), search);
		if (it == clientList.end()) {
			cout << search << "입력하신 정보를 찾을 수 없습니다.\n";
		}

	}

private:
	vector<Client*>clientList;
};