#ifndef __SHOPINFOMANAGER_H__
#define __SHOPINFOMANAGER_H__

#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"
#include "ClientManager.h"
#include "ProductManager.h"
/**
* 주문정보를 관리하는 클래스
*/
class ShopInfoManager {
public:
	ShopInfoManager(ClientManager&, ProductManager&);

	void ShopMainMenu();		// 주문메인메뉴
	void add_Shoplist();		// 주문하기
	void shoplist_print();		// 주문조회
	void search_shoplist();		// 주문검색
	void update_shop();			// 주문변경
	void delete_shoplist();		// 주문내역 삭제

	int smenu();				// 정해진 범위 외 입력 예외처리
	int ssearach_menu();		// 정해진 범위 외 입력 예외처리

	void showShoplist(ShopInfo* shopinfo);	//ShopInfolist 벡터 출력
	~ShopInfoManager();

	vector<string> parseCSV(istream&, char);	//파일입출력을 위한 함수
	void print_Shopmenu();
private:
	vector<ShopInfo*> ShopInfolist;     // 주문정보가 저장되는 벡터
	ClientManager& CM;		// 고객정보를 관리하는 객체
	ProductManager& PM;		// 제품정보를 관리하는 객체
};
#endif