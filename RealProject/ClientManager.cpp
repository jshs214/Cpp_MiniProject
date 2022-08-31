#include "Client.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ClientManager {
public:
	void add_Client()		// 입력
	{
		string name;
		string clientid;
		string phonenumber;
		string address;

		cout << "이름 : "; cin >> name;
		cout << "고객 ID(PK) : "; cin >> clientid;
		cout << "전화번호 : "; cin >> phonenumber;
		cout << "주소 : "; cin.ignore(); getline(cin, address);

		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()		//조회
	{
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< "이름 : " << c->getName() << endl
				<< "고객 ID(PK): " << c->getclientID() << endl
				<< "전화번호 :" << c->getPhoneNumber() << endl
				<< "주소 : " << c->getAddress() << endl;
			});
	}

	void search_client()		//검색
	{
		string input;

		cout << "검색 : "; cin >> input;

		for(auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name == input) {
				cout << "===========검색결과==========" << endl
					<< "이름 : " << (*it)->getName() << endl
					<< "고객 ID(PK): " << (*it)->getclientID() << endl
					<< "전화번호 :" << (*it)->getPhoneNumber() << endl
					<< "주소 : " << (*it)->getAddress() << endl;
			}
			else
			{
				cout << "탐색 x"<< endl;
			}
		}
	}

	void delete_client()		//삭제
	{
		string input;
		cout << "삭제할 고객 이름 : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();

			if (sch_name == input) {
				clientList.erase(it);
				cout << input <<"정보가 삭제되었습니다." << endl;
				break;
			}

			else
			{
				cout << "탐색 x" << endl;
			}
		}
	}

private:
	vector<Client*>clientList;
};