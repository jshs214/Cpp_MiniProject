#ifndef __PRODUCT_H__
#define __PRODUCT_H__

#include <iostream>

using namespace std;

class Product{
public:
    Product(int = 0, string = "", int = 0);

    int getProductID() const;
    void setProductID(int&);
    string getProductName() const;
    void setProductName(string&);
    int getPrice() const;
    void setPrice(int&);
private:
    int m_productID;        // 力前 ID
    string m_productName;   // 力前 疙
    int m_price;            // 力前 啊拜

};
#endif          // __CLIENT_H__