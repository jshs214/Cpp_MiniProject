#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__
#include "Client.h"
#include <vector>

class ClientManager {
public:
	ClientManager();
	
	void ClientMainMenu();	//고객 메인 화면
	void add_Client();		//고객 추가
	void client_print();	// 조회
	void search_client();	// 검색
	void delete_client();	// 삭제
	void update_client();	// 정보 변경

	int cpmenu();	// 고객 관리 메뉴에서 정해진 범위만 받도록
	int csearach_menu();	//검색메뉴 예외값 입력 처리
	int cupdate_menu();		//변경메뉴 예외값 입력 처리
	
	void showClientlist(Client* clientinfo);	//clientList 출력

	~ClientManager();

	vector<string> parseCSV(istream&, char);
	vector<Client*>& getClientList();
private:
	vector<Client*>clientList;
};
#endif