#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include <iostream>
#include<string>
#include<Windows.h>
#include "Line.h"

using namespace std;

class Product{
public:
    Product(string = 0, string = "", int = 0,  string="", int = 0);
    // productID, productName, price, producttype, stock

    string getProductID() const;
    void setProductID(string&);
    string getProductName() const;
    void setProductName(string&);
    int getPrice() const;
    void setPrice(int&);
    string getProductType() const;
    int getStock() const;
    void setStock(int&);

private:
    string m_productID;        // 力前 ID
    string m_productName;   // 力前 疙
    int m_price;            // 力前 啊拜
    string m_productType;   // 力前 辆幅
    int m_stock; //力前 俺荐
};
#endif          // __PRODUCT_H__