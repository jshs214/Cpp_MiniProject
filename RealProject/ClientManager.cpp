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

		system("cls");
		cout << " [신규 고객 정보 입력]" << endl;
		cout << "이름 : "; cin >> name;
		cout << "고객 ID(PK) : "; cin >> clientid;
		cout << "전화번호 : "; cin >> phonenumber;
		cout << "주소 : "; cin.ignore(); getline(cin, address);

		Client* newClient = new Client(name, clientid,phonenumber, address);
		clientList.push_back(newClient);
	}

	void add_client_print()		//조회
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                               고객정보조회                             " << endl;
		cout << "========================================================================" << endl;
		cout << "       이름      /     고객 ID     /     전화번호      /       주소" << endl;
		cout << "========================================================================" << endl;
	
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< c->getName() << " / "
				<< c->getclientID() << " / "
				<<  c->getPhoneNumber() << " / "
				<<  c->getAddress() << endl;
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
				cout << "========================================================================" << endl;
				cout << "                               검색결과                             " << endl;
				cout << "========================================================================" << endl;
				cout << "       이름      /     고객 ID     /     전화번호      /       주소" << endl;
				cout << "========================================================================" << endl;
				cout << "이름 : " << (*it)->getName() << endl
					<< "고객 ID(PK): " << (*it)->getclientID() << endl
					<< "전화번호 :" << (*it)->getPhoneNumber() << endl
					<< "주소 : " << (*it)->getAddress() << endl;
			}
			else if(it == clientList.end())
			{
					cout << "탐색 실패";
			}
		}
	}

	void delete_client()		//삭제 고객 ID는 pk키로
	{
		string input;
		cout << "삭제할 고객명 입력하세요 : "; cin >> input;		// 고객명 -> 고객 ID로 수정해야함

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();

			if (sch_name == input) {
				clientList.erase(it);
				cout << input <<"정보가 삭제되었습니다." << endl;
				break;
			}

			
		}
	}

	void update_client()	//값 변경
	{
		string input;
		int up_num;
		string up_data;

		cout << "정보 수정 할 고객명 : "; cin >> input;		// 고객 ID로 수정해야함

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();		//입력한 고객명 데이터가 있으면

			if (sch_name == input) {
				cout << "1. 이름 변경  2. 전화번호 변경 3. 주소 변경" << endl;
				cin >> up_num;
				switch (up_num)
				{
				case 1:		//이름 변경
					cout << "변경할 이름 입력"<<endl;		cin >> up_data;
					(*it)->setName(up_data);
					break;

				case 2:		//전화번호 변경
					cout << "변경할 전화번호 입력" << endl;	cin >> up_data;
					(*it)->setPhoneNumber(up_data);
					break;

				case 3:		//주소 변경
					cout << "변경할 주소 입력 : " ;	cin >> up_data;
					(*it)->setAddress(up_data);
					break;
				}
			}

			/*else
			{
				cout << "탐색 실패";
			}*/
		}
	}

private:
	vector<Client*>clientList;
};