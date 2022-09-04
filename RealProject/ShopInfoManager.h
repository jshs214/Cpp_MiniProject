#ifndef __SHOPINFOMANAGER_H__
#define __SHOPINFOMANAGER_H__

#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"


class ShopInfoManager {
public:
	void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList);       // �ֹ��ϱ�
	void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList);     // ��ȸ
	void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList);    //�˻�

	vector<ShopInfo*> getShopInfolist();

private:
	vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
};
#endif