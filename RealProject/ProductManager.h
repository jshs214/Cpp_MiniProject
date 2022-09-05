#ifndef __PRODUCTMANAGER_H__
#define __PRODUCTMANAGER_H__
#include "Product.h"
#include "ShopInfoManager.h"

class ProductManager {
public:

	ProductManager();
	void add_Product();		// ��ǰ �߰�
	void Product_print();	// ��ȸ
	void search_Product();	// �˻�
	void delete_Product();	// ����
	void update_product();	// ���� ����

	int psearach_menu();		// �˻� �޴� �Է� ����ó��
	int pupdate_menu();	// ���� �޴� �Է� ���� ó��
	~ProductManager();

	vector<string> parseCSV(istream&, char);
	vector<Product*>& getproductList();

private:
	vector<Product*>productList;
};
#endif