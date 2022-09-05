#ifndef __SHOPINFOMANAGER_H__
#define __SHOPINFOMANAGER_H__

#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"


class ShopInfoManager {
public:
	ShopInfoManager();
	void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList);       // �ֹ��ϱ�
	void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList);     // ��ȸ
	void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList);    //�˻�

	int ssearach_menu();		// ShopInfo �˻� �޴� �Է� ����ó��
	~ShopInfoManager();

	vector<string> parseCSV(istream&, char);
	vector<ShopInfo*>& getShopInfolist();
	void print_Shoplist(vector<ShopInfo*>& ShopInfolist);
	void print_Shopmenu();
private:
	vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
};
#endif