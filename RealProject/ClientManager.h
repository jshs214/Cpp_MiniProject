#ifndef __CLIENTMANAGER_H__
#define __CLIENTMANAGER_H__

#include "Client.h"
#include <vector>

class ClientManager {

public:
	ClientManager();
	void add_Client();		//�� �߰�
	void client_print();	// ��ȸ
	void search_client();	// �˻�
	void delete_client();	// ����
	void update_client();	// ���� ����


	vector<Client*>& getClientList();

private:
	vector<Client*>clientList;

};
#endif