#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include "Client.h"
#include <vector>

class ClientManager {

public:
	ClientManager();
	void add_Client();		//고객 추가
	void client_print();	// 조회
	void search_client();	// 검색
	void delete_client();	// 삭제
	void update_client();	// 정보 변경


	vector<Client*>& getClientList();

private:
	vector<Client*>clientList;

};
#endif