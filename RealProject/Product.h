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
    int m_productID;        // 力前 ID
    string m_productName;   // 力前 疙
    int m_price;            // 力前 啊拜
    int m_stock;            // 力前 俺荐
    string m_productType;   // 力前 辆幅
};
#endif          // __CLIENT_H__