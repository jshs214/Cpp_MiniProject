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

	void ShopMainMenu();		// �ֹ����θ޴�
	void add_Shoplist();		// �ֹ��ϱ�
	void shoplist_print();		// �ֹ���ȸ
	void search_shoplist();		// �ֹ��˻�
	void update_shop();			// �ֹ�����
	void delete_shoplist();		// �ֹ����� ����

	int smenu();				// ������ ���� �� �Է� ����ó��
	int ssearach_menu();		// ������ ���� �� �Է� ����ó��

	void showShoplist(ShopInfo* shopinfo);	//ShopInfolist ���� ���
	~ShopInfoManager();

	vector<string> parseCSV(istream&, char);	//����������� ���� �Լ�
	void print_Shopmenu();
private:
	vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
	ClientManager& CM;
	ProductManager& PM;
};
#endif