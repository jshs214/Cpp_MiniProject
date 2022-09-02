#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__
#include "Product.h"

class ProductManager {
public:

	ProductManager();
	void add_Product();		// 제품 추가
	void Product_print();	// 조회
	void search_Product();	// 검색
	void delete_Product();	// 삭제
	void update_product();	// 정보 변경

	vector<Product*>& getproductList();

private:
	vector<Product*>productList;
};
#endif