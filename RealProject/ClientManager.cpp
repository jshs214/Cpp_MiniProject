#include "ClientManager.h"

#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#define C_YLLW "\033[33m"
#define C_NRML "\033[0m"

/**
* 생성자에서 Client.txt 파일이 존재하면, ','로 구분한 텍스트를 한줄씩 불러옴.
* @exception 파일이 없으면 로드되지 않음.
*/
ClientManager::ClientManager()
{
	ifstream file;
	file.open("Client.txt");
	if (!file.fail()) {
		while (!file.eof()) {
			vector<string> row = parseCSV(file, ',');
			if (row.size()) {

				Client* c = new Client(row[0], row[1], row[2], row[3]);
				clientList.push_back(c);
			}
		}
	}
	cout << "Client.txt을 로드하였습니다." << endl;
	Sleep(1000);
	file.close();
}

/**
* 소멸자에서 Client.txt 파일이 존재하면 productList벡터의 ','로 구분한 텍스트 한줄 씩 저장
* @exception 파일이 없으면 파일 생성.
*/
ClientManager::~ClientManager()
{
	ofstream fs("Client.txt");
	if (!fs) {
		cout << "출력할 파일을 열 수 없습니다.";
		Sleep(1000);
	}

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		fs << (*it)->getName() << ", "
			<< (*it)->getclientID() << ", "
			<< (*it)->getPhoneNumber() << ", "
			<< (*it)->getAddress() << endl;
	}
	cout << "Client.txt을 저장했습니다." << endl;
	Sleep(1000);
	fs.close();

}

/**
* @return 고객정보가 저장된 clientList벡터 반환
*/
vector<Client*>& ClientManager::getClientList()
{
	return clientList;
}

/**
* 고객관리메인
* 화면에서 입력값을 받아 입력, 조회, 검색, 삭제, 변경 등 함수를 호출
* 
@exception 정해진 입력값이 아닐 경우 예외처리
*/
void ClientManager::ClientMainMenu()
{
	int back = 0;
	int Client_menu;	//1. 입력 2. 조회 3. 검색 4. 삭제 5. 변경
	Client_menu = cpmenu();		//고객메뉴에서 정해진 범위만 입력 받는 함수
	switch (Client_menu)
	{
	case 0:	//메인화면으로
		break;
	case 1:		//입력
		add_Client();
		break;
	case 2:		//조회
		client_print();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
	case 3:		//검색
		search_client();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	case 4:		//삭제
		delete_client();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	case 5:		//변경
		update_client();
		cout << "종료 (0) "; cin >> back;
		if (back == 0)break;
		break;
	}
}

/**
* 고객정보입력
* 고객정보를 관리하는 clientList벡터에 입력한 데이터를 추가
*
* @exception 고객ID(PK)를 중복검사 해 중복이면 추가되지 않도록 예외처리.
*/
void ClientManager::add_Client()
{
	string name, clientid, phonenumber, address;

	system("cls");
	cout << LINE << endl;
	cout << "                                            신규 고객 정보등록" << endl;
	cout << LINE << endl;

	cout << "이름 : "; cin >> name;
	cout << "고객 ID(PK) : "; cin >> clientid;
	cout << "전화번호 (-구분없이 입력) : "; cin >> phonenumber;
	cout << "주소 : "; cin.ignore(); getline(cin, address);

	while (1) {			//clientID (PK) 중복검사 (같으면 재입력)
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
			cout << " 중복 id 입니다. 다시 입력해 주세요 (종료 0): ";
			cin >> clientid;
			if (clientid == "0")	return;		//종료조건
		}
	}

	Client* newClient = new Client(name, clientid, phonenumber, address);
	clientList.push_back(newClient);

	cout << "[신규고객 등록 완료]" << endl;
	Sleep(1000);	//Delay 1초
}

/**
* 고객정보조회
* 고객정보를 관리하는 clientList벡터에 입력된 데이터를 조회.
*/
void ClientManager::client_print()
{

	system("cls");
	cout << LINE << endl;
	cout << "                                            고객정보조회                                            " << endl;
	cout << LINE << endl;
	cout << "       이름     /   고객 ID (PK)   /     전화번호      /       주소" << endl;
	cout << LINE << endl;

	sort(clientList.begin(), clientList.end(), [](Client* a, Client* b) {		//이름 기준으로 정렬
		return a->getName() < b->getName();
		});

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		showClientlist(*it);		//clientList 출력
	}
	cout << "[고객정보 조회 완료]" << endl;
	cout << LINE << endl;
	cout << "[총 " << clientList.size() << "명의 정보가 있습니다]" << endl;
	cout << LINE << endl;
}

/**
* 고객정보검색
* 문자열을 입력받아 문자열이 고객정보의 입력된 데이터에 포함되는 데이터가 있으면 clientList의 데이터 검색.
* 
* @exception 정해진 입력값이 아닐 경우 예외처리
*/
void ClientManager::search_client()	
{
	bool flag = false;
	int num = 0;
	string input;	//검색 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수
	system("cls");
	cout << LINE << endl;
	cout << "                                            고객명 검색" << endl;
	cout << LINE << endl;
	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
			showClientlist(*it);		//clientList 출력
	}
	cout << LINE << endl;
	cout << "1. 고객명 검색 2. 고객 ID 검색 "<<endl;
	cout << LINE << endl;

	num=csearach_menu();	//1. 고객명 검색 2. 고객ID 검색
	switch (num)
	{
	case 1:
		cout << "고객명 검색 : "; cin >> input;

		cout << LINE << endl;
		cout << "                                       [입력한 고객명 : " << input << " 검색결과]" << endl;
		cout << LINE << endl;
		cout << "       이름     /   고객 ID (PK)   /     전화번호      /       주소" << endl;
		cout << LINE << endl;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name.find(input) != -1) {	//clientList의 name에 입력한 문자열이 찾아지면 관련정보 출력
				flag = true;
				printf("%s", C_YLLW);		//글자색 찾은 데이터 노란색
				showClientlist(*it);		//clientList 출력
				printf("%s", C_NRML);		//글자 색 복귀
			}
		}
		if (flag == false)
			cout << "[입력하신 고객명이 없습니다]" << endl;
		cout << LINE << endl;
		break;		// case 1 break;

	case 2:
		cout << "고객 ID : "; cin >> input;

		cout << LINE << endl;
		cout << "                                       [입력한 고객 ID : " << input << " 검색결과]" << endl;
		cout << LINE << endl;
		cout << "       이름     /   고객 ID (PK)   /     전화번호      /       주소" << endl;
		cout << LINE << endl;
		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_id = (*it)->getclientID();
			if (sch_id.find(input) != -1) {		//clientList의 clientID에 입력한 문자열이 찾아지면 관련정보 출력
				flag = true;
				printf("%s", C_YLLW);
				showClientlist(*it);		//clientList 출력
				printf("%s", C_NRML);
			}
		}
		if (flag == false)
			cout << "[입력하신 고객 ID가 없습니다]" << endl;
		cout << LINE << endl;
		break;
	}
}

/**
* 고객정보삭제
* PK 문자열을 입력받아 문자열이 고객정보의 PK와 일치하면 해당 clientList의 데이터 삭제.
*/
void ClientManager::delete_client()
{
	bool flag = false;
	string input;	//삭제 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수
	system("cls");

	cout << LINE << endl;
	cout << "                                            고객 정보 삭제" << endl;
	cout << LINE << endl;
	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		showClientlist(*it);		//clientList 출력
	}
	cout << LINE << endl;
	cout << "삭제할 고객 ID 입력하세요 : "; cin >> input;

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		auto sch_ID = (*it)->getclientID();
		if (sch_ID == input) {		//clientList의 id와 입력한 문자열이 같으면 삭제
			flag = true;
			clientList.erase(it);
			cout << input << " 에 대한 정보가 삭제되었습니다." << endl;
			cout << "[고객정보 삭제 완료]" << endl;
			break;
		}
	}
	if (flag == false)
		cout << "[입력하신 고객 ID가 없습니다]" << endl;
	cout << LINE << endl;
}

/**
* 고객정보변경
* 변경할 정보를 선택 후 입력받아 해당 clientList의 데이터 변경.
* 
* @exception 정해진 입력값이 아닐 경우 예외처리
*/
void ClientManager::update_client()
{
	int num = 0;
	bool flag = false;
	string up_data ,input;	// 업데이트 시 변경 할 데이터, //변경 시 수정할 데이터와 매칭하기 위해 입력받는 지역변수

	system("cls");
	cout << LINE << endl;
	cout << "                                            고객 정보 변경                              " << endl;
	cout << LINE << endl;
	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		showClientlist(*it);		//clientList 출력
	}
	cout << LINE << endl;
	cout << "고객 ID 입력 : "; cin >> input;

	for (auto it = clientList.begin(); it != clientList.end(); ++it)
	{
		auto sch_name = (*it)->getclientID();
		if (sch_name == input) {	//clientList의 id와 입력한 문자열이 같으면 정보변경
			flag = true;
			cout << "1. 이름 변경  2. 전화번호 변경 3. 주소 변경" << endl;	
			num = cupdate_menu();	// 1 ~ 3 이외 예외값 입력 처리함수
			switch (num)
			{
			case 1:		//이름 변경
				cout << "변경할 이름 입력" << endl;		cin >> up_data;
				(*it)->setName(up_data);
				cout << "[이름 변경 완료]" << endl;
				break;

			case 2:		//전화번호 변경
				cout << "변경할 전화번호 입력" << endl;	cin >> up_data;
				(*it)->setPhoneNumber(up_data);
				cout << "[전화번호 변경 완료]" << endl;
				break;

			case 3:		//주소 변경
				cout << "변경할 주소 입력 : ";	cin.ignore(); getline(cin, up_data);
				(*it)->setAddress(up_data);
				cout << "[주소 변경 완료]" << endl;
				break;
			}
		}
	}
		if (flag == false)
			cout << "[입력하신 고객 ID가 없습니다]" << endl;

		cout << LINE << endl;
	
}

/**
* clientList에 입력된 데이터 출력함수
*/
void ClientManager::showClientlist(Client* clientinfo)
{
	cout << clientinfo->getName() << " / "
		<< clientinfo->getclientID() << " / "
		<< clientinfo->getPhoneNumber() << " / "
		<< clientinfo->getAddress() << endl;
}

/**
* 입력값 예외처리 함수
* @exception 정해진 입력값이 아닐 경우 예외처리
* @return 입력값 반환
*/
int ClientManager::csearach_menu()
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin menu 에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]"<<endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 3)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

/**
* 입력값 예외처리 함수
* @exception 정해진 입력값이 아닐 경우 예외처리
* @return 입력값 반환
*/
int ClientManager::cupdate_menu()
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu > 0 && menu < 4)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

/**
* 입력값 예외처리 함수
* @exception 정해진 입력값이 아닐 경우 예외처리
* @return 입력값 반환
*/
int ClientManager::cpmenu()
{
	int menu;
	cin >> menu;
	if (!cin) {		// cin에 숫자만 입력 받도록
		cout << "[메뉴 번호만 입력해주세요]";
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		Sleep(1000);
	}
	else if (menu >= 0 && menu < 6)
		return menu;
	else {
		cout << "[메뉴 번호만 입력해주세요]" << endl;
		Sleep(1000);
	}
	return 0;
}

/**
* CSV 파일의 형식을 한 행씩 가져옴
* @param istream& file 가져올 내용이 들어있는 파일
* @param char delimiter 구분 문자
* @return 한 행씩 반환
*/
vector<string> ClientManager::parseCSV(istream& file, char delimiter)
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
