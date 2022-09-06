#ifndef __SHOPINFOMANAGER_H__
#define __SHOPINFOMANAGER_H__

#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"

#include "ClientManager.h"
#include "ProductManager.h"

class ShopInfoManager {
public:
	ShopInfoManager(ClientManager&, ProductManager&);

	void ShopMainMenu();	// �ֹ��������θ޴�
	void add_Shoplist();       // �ֹ��ϱ�
	void shoplist_print();     // ��ȸ
	void search_shoplist();    //�˻�

	int smenu();
	int ssearach_menu();		// ShopInfo �˻� �޴� �Է� ����ó��
	~ShopInfoManager();

	vector<string> parseCSV(istream&, char);
	void print_Shopmenu();
private:
	vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
	ClientManager& CM;
	ProductManager& PM;
};
#endif