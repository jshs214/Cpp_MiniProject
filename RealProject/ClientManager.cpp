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
		cout << "========================================================================" << endl;
		cout << "                           신규 고객 정보등록                             " << endl;
		cout << "========================================================================" << endl;
		cout << "이름 : "; cin >> name;
		cout << "고객 ID(PK) : "; cin >> clientid;
		cout << "전화번호 : "; cin >> phonenumber;
		cout << "주소 : "; cin.ignore(); getline(cin, address);

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_PK = (*it)->getclientID();

			if (sch_PK == clientid) {
				while(1){
				cout << " 중복 id 입니다. 다시 입력해 주세요 : ";
				cin >> clientid;
					if (sch_PK != clientid)	break;
				}
			}

		}

		Client* newClient = new Client(name, clientid ,phonenumber, address);
		clientList.push_back(newClient);

		cout << "[신규 고객 등록 완료]" << endl;

	}

	void add_client_print()		//조회
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                               고객정보조회                             " << endl;
		cout << "========================================================================" << endl;
		cout << "       이름     /   고객 ID (PK)   /     전화번호      /       주소" << endl;
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
		int sch_num;		//검색할 정보
		string up_data;
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                             고객명 검색                             " << endl;
		cout << "========================================================================" << endl;
		cout << "고객명 검색 : "; cin >> input;

		cout << "========================================================================" << endl;
		cout << "       이름      /     고객 ID     /     전화번호      /       주소" << endl;
		cout << "========================================================================" << endl;
		
		for(auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name == input) {
				cout << (*it)->getName() << " / "
					<< (*it)->getclientID() << " / "
					<< (*it)->getPhoneNumber() << " / "
					<< (*it)->getAddress() << endl;
			}
		}

	}

	void delete_client()		//삭제 고객 ID는 pk키로
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                             고객 정보 삭제                              " << endl;
		cout << "========================================================================" << endl;
		string input;
		cout << "삭제할 고객 ID 입력하세요 : "; cin >> input;		// 고객명 -> 고객 ID로 수정해야함

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_ID = (*it)->getclientID();

			if (sch_ID == input) {
				clientList.erase(it);
				cout << input <<" 에 대한 정보가 삭제되었습니다." << endl;
				break;
			}
		}
	}

	void update_client()	//값 변경
	{
		cout << "========================================================================" << endl;
		cout << "                             고객 정보 변경                              " << endl;
		cout << "========================================================================" << endl;
		string input;	//고객 ID 위한
		int up_num;	// 업데이트정보 구분위한 변수
		string up_data;	// 업데이트 할 데이터

		cout << "고객 ID 입력 : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getclientID();		//입력한 고객 ID 데이터가 있으면

			if (sch_name == input) {
				cout << "1. 이름 변경  2. 전화번호 변경 3. 주소 변경" << endl;
				cin >> up_num;	//변경할 정보

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

		}
	}

private:
	vector<Client*>clientList;
};