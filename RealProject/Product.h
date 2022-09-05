#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>
#include "Line.h"
#include <Windows.h>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Product{
public:
    Product(string = 0, string = "", int = 0,  string="", int = 0);

    string getProductID() const;
    void setProductID(string&);
    string getProductName() const;
    void setProductName(string&);
    int getPrice() const;
    void setPrice(int&);
    string getProductType() const;
    void setProductType(string &);
    int getStock() const;
    void setStock(int&);

private:
    string m_productID;        // ��ǰ ID
    string m_productName;   // ��ǰ ��
    int m_price;            // ��ǰ ����
    string m_productType;   // ��ǰ ����
    int m_stock; //��ǰ ����
};
#endif          // __CLIENT_H__