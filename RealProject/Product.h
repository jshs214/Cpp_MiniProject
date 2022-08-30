#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>

using namespace std;

class Product{
public:
    Product(int = 0, string = "", int = 0, int = 0, string="");

    int getProductID() const; 
    void setProductID(int&);
    string getProductName() const;
    void setProductName(string&);
    int getPrice() const;
    void setPrice(int&);
    int getStock() const;
    void setStock(int&);
    string getProductType() const;
    void setProductType(string &);

private:
    int m_productID;        // ��ǰ ID
    string m_productName;   // ��ǰ ��
    int m_price;            // ��ǰ ����
    int m_stock;            // ��ǰ ����
    string m_productType;   // ��ǰ ����
};
#endif          // __CLIENT_H__