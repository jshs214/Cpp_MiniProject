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

		cout << "제품코드 : "; cin >> productID;
		cout << "제품명 : "; cin >> productName;
		cout << "가격 : "; cin >> price;
		cout << "수량 : "; cin >> stock;
		cout << "종류 : "; cin >> productType;

		Product* newProduct = new Product(productID, productName, price, stock, productType);
		productList.push_back(newProduct);
	}

	void add_Product_print()
	{
		for_each(productList.begin(), productList.end(), [](Product* p) {
			cout << "제품코드 : " << p->getProductID() << endl
				<< "제품명 : " << p->getProductName() << endl
				<< "가격 : " << p->getPrice() << endl
				<< "수량 : " << p->getStock() << endl
				<< "종류 : " << p->getProductType() << endl;
			});
	}
private:
	vector<Product*>productList;
};