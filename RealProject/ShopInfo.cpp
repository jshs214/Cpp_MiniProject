#include "ShopInfo.h"

#include <iostream>

ShopInfo::ShopInfo(int shopkey, string shoppid, string productName, string productType, int price,
    int sstock, string name, string shopcid, string phonenumber, string address,
    int year, int mon, int mday)
    : m_shopkey(shopkey), m_productID(shoppid), m_productname(productName),
    m_producttype(productType), m_price(price), m_sstock(sstock), m_name(name), 
    m_clientID(shopcid), m_phonenumber(phonenumber), m_address(address),
    m_year(year),m_mon(mon),m_mday(mday)
{
}
int ShopInfo::getShopkey() const
{
    return m_shopkey;
}
void ShopInfo::setShopkey(int& shopkey)
{
    m_shopkey=shopkey;
}
string ShopInfo::getclientID() const
{
    return m_clientID;
}
string ShopInfo::getProductID() const
{
    return m_productID;
}

int ShopInfo::getStock() const
{
    return m_sstock;
}
void ShopInfo::setStock(int& sstock)
{
    m_sstock = sstock;
}
string ShopInfo::getproductName() const
{
    return m_productname;
}

string ShopInfo::getproductType() const
{
    return m_producttype;
}

int ShopInfo::getPrice() const
{
    return m_price;
}
string ShopInfo::getname() const
{
    return m_name;
}
string ShopInfo::getphoneNumber() const
{
    return m_phonenumber;
}
void ShopInfo::setphoneNumber(string& phonenumber)
{
    m_phonenumber = phonenumber;
}
string ShopInfo::getaddress() const
{
    return m_address;
}
void ShopInfo::setaddress(string& address)
{
    m_address = address;
}
int ShopInfo::getyear() const
{
    return m_year;
}
int ShopInfo::getmonth() const
{
    return m_mon;
}
int ShopInfo::getday() const
{
    return m_mday;
}