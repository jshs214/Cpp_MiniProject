#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__
#include "Product.h"

class ProductManager {
public:

	ProductManager();
	void add_Product();		// ��ǰ �߰�
	void Product_print();	// ��ȸ
	void search_Product();	// �˻�
	void delete_Product();	// ����
	void update_product();	// ���� ����

	vector<Product*>& getproductList();

private:
	vector<Product*>productList;
};
#endif