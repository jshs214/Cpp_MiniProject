#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__

#include <iostream>

using namespace std;
/**
* 주문정보의 데이터를 관리하는 클래스
* @author 홍성주
*/
class ShopInfo {
public:
    ShopInfo(int = 0, string = "", string = "", string = "", int = 0, int = 0, string = "",
             string = "", string = "", string = "",int =0,int =0,int =0);
            //shopkey, shoppid, productName, productType, price, sstock, name, 
            //shopcid, phonenumber, address, year, mon, mday
    int getShopkey() const;
    void setShopkey(int&);
    string getclientID() const;
    string getProductID() const;   
    int getStock() const;
    void setStock(int& );
    string getproductName() const; 
    string getproductType() const;
    int getPrice() const;
    string getname() const;
    string getphoneNumber() const;
    void setphoneNumber(string&);
    string getaddress() const;
    void setaddress(string&);

    int getyear() const;
    int getmonth() const;
    int getday() const;

private:
    int m_shopkey;          // 주문번호(PK)
    string m_clientID;      // 고객 ID
    string m_productID;     // 제품 ID
    int m_sstock;           // 수량
    string m_name;          // 고객 이름
    string m_phonenumber;   // 고객 전화번호
    string m_address;       // 고객 주소
    string m_productname;   // 제품 명
    int m_price;            // 제품 가격
    string m_producttype;   // 제품 종류
    int m_year, m_mon, m_mday;      //연, 월, 일
};
#endif          // __SHOPINFO_H__