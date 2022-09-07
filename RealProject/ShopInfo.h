#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__

#include <iostream>

using namespace std;
/**
* �ֹ������� �����͸� �����ϴ� Ŭ����
* @author ȫ����
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
    int m_shopkey;          // �ֹ���ȣ(PK)
    string m_clientID;      // �� ID
    string m_productID;     // ��ǰ ID
    int m_sstock;           // ����
    string m_name;          // �� �̸�
    string m_phonenumber;   // �� ��ȭ��ȣ
    string m_address;       // �� �ּ�
    string m_productname;   // ��ǰ ��
    int m_price;            // ��ǰ ����
    string m_producttype;   // ��ǰ ����
    int m_year, m_mon, m_mday;      //��, ��, ��
};
#endif          // __SHOPINFO_H__