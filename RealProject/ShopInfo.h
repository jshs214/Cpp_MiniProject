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
    string getclientID() const;     // �� ID
    void setclientID(string&);
    string getProductID() const;    
    void setProductID(string&);
    int getStock() const;
    void setStock(int& );

    string getproductName() const;    // ��ǰ ID
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

    string m_clientID;      // �� ID
    string m_name;          // �� �̸�
    string m_phoneNumber;   // �� ��ȭ��ȣ
    string m_address;       // �� �ּ�
    string m_productID;        // ��ǰ ID
    string m_productname;   // ��ǰ ��
    int m_price;            // ��ǰ ����
    string m_producttype;   // ��ǰ ����
    string m_phonenumber;
    int m_year, m_mon, m_mday;
};
#endif          // __CLIENT_H__