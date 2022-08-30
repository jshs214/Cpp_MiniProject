#include "Product.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ProductManager {
public:
	void add_Product()
	{
		int productID;
		string productName;
		int price;
		int stock;
		string productType;

		cout << "��ǰ�ڵ� : "; cin >> productID;
		cout << "��ǰ�� : "; cin >> productName;
		cout << "���� : "; cin >> price;
		cout << "���� : "; cin >> stock;
		cout << "���� : "; cin >> productType;

		Product* newProduct = new Product(productID, productName, price, stock, productType);
		productList.push_back(newProduct);
	}

	void add_Product_print()
	{
		for_each(productList.begin(), productList.end(), [](Product* p) {
			cout << "��ǰ�ڵ� : " << p->getProductID() << endl
				<< "��ǰ�� : " << p->getProductName() << endl
				<< "���� : " << p->getPrice() << endl
				<< "���� : " << p->getStock() << endl
				<< "���� : " << p->getProductType() << endl;
			});
	}
private:
	vector<Product*>productList;
};