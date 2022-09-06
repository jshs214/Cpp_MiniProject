#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__
#include "Product.h"

class ProductManager {
public:

	ProductManager();
	void ProductMainMenu();	// 제품 메인 메뉴
	void add_Product();		// 제품 추가
	void Product_print();	// 조회
	void search_Product();	// 검색
	void delete_Product();	// 삭제
	void update_product();	// 정보 변경

	int cpmenu();			// 제품 관리 메뉴에서 정해진 범위만 받도록
	int psearach_menu();		// 검색 메뉴 입력 예외처리
	int pupdate_menu();	// 변경 메뉴 입력 예외 처리
	int update_data(); // 예외 처리
	void showProductlist(Product* productinfo);
	~ProductManager();

	vector<string> parseCSV(istream&, char);
	vector<Product*>& getproductList();

private:
	vector<Product*>productList;
};
#endif