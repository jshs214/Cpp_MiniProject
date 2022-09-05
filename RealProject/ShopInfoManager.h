#ifndef __SHOPINFOMANAGER_H__
#define __SHOPINFOMANAGER_H__

#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"


class ShopInfoManager {
public:
	ShopInfoManager();
	void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList);       // 주문하기
	void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList);     // 조회
	void search_shoplist(vector<Client*>& clientList, vector<Product*>& productList);    //검색

	int ssearach_menu();		// ShopInfo 검색 메뉴 입력 예외처리
	~ShopInfoManager();

	vector<string> parseCSV(istream&, char);
	vector<ShopInfo*>& getShopInfolist();
	void print_Shoplist(vector<ShopInfo*>& ShopInfolist);
	void print_Shopmenu();
private:
	vector<ShopInfo*> ShopInfolist;     // ShopInfo의 벡터
};
#endif