#ifndef __PRODUCT_H__
#define __PRODUCT_H__
#include <iostream>
#include<string>
#include<Windows.h>
#include "Line.h"

using namespace std;
/**
* 제품정보의 데이터를 관리하는 클래스
*/
class Product{
public:
    // 제품코드, 제품명, 가격, 제품종류, 재고
    Product(string = 0, string = "", int = 0,  string="", int = 0);
    

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
    string m_productID;        // 제품 ID
    string m_productName;   // 제품 명
    int m_price;            // 제품 가격
    string m_productType;   // 제품 종류
    int m_stock; //제품 개수
};
#endif          // __PRODUCT_H__