#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__

#include <iostream>

using namespace std;

class ShopInfo {
public:
    ShopInfo(int = 0, string = "", string = "", string = "",
        int = 0, int = 0, string = "", string = "",
        string = "", string = "",int =0,int =0,int =0);

    int getShopkey() const;
    void setShopkey(int&);
    string getclientID() const;     // 绊按 ID
    void setclientID(string&);
    string getProductID() const;    
    void setProductID(string&);
    int getStock() const;
    void setStock(int& );

    string getproductName() const;    // 力前 ID
    string getproductType() const;
    int getPrice() const;
    string getname() const;
    string getphoneNumber() const;
    string getaddress() const;
    int getyear() const;
    int getmonth() const;
    int getday() const;
private:
    int m_shopkey;
    string m_shopcid;
    string m_shoppid;
    int m_sstock;

    string m_clientID;      // 绊按 ID
    string m_name;          // 绊按 捞抚
    string m_phoneNumber;   // 绊按 傈拳锅龋
    string m_address;       // 绊按 林家
    string m_productID;        // 力前 ID
    string m_productname;   // 力前 疙
    int m_price;            // 力前 啊拜
    string m_producttype;   // 力前 辆幅
    string m_phonenumber;
    int m_year, m_mon, m_mday;
};
#endif          // __CLIENT_H__