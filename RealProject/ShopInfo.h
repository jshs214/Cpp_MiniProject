#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__

#include <iostream>

using namespace std;

class ShopInfo {
public:
    ShopInfo(int = 0, string = "", string = "", string = "", int = 0, int = 0, string = "", string = "", string = "", string = "");

    int getShopkey() const;
    void setShopkey(int&);
    string getclientID() const;     // 绊按 ID
    void setclientID(string&);
    string getProductID() const;    // 力前 ID
    void setProductID(string&);
    int getStock() const;
    void setStock(int& );
    string getproductName() const;    // 力前 ID
    void setproductName(string&);
    string getproductType() const;
    void setproductType(string&);
    int getPrice() const;
    void setPrice(int &);
    string getname() const;
    void setname(string &);
    string getphoneNumber() const;
    void setphoneNumber(string&); 
    string getaddress() const;
    void setaddress(string&);
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
};
#endif          // __CLIENT_H__