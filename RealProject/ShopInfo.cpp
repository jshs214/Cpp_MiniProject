
#include "ShopInfo.h"

#include <iostream>

ShopInfo::ShopInfo(int shopkey, string shoppid, string productName, string productType, int price,
    int sstock, string name, string shopcid, string phonenumber, string address)
    : m_shopkey(shopkey), m_productID(shoppid), m_productname(productName), m_producttype(productType), m_price(price),
    m_sstock(sstock), m_name(name), m_shopcid(shopcid), m_phonenumber(phonenumber), m_address(address)
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
    return m_shopcid;
}

void ShopInfo::setclientID(string& shopcid)
{
    m_shopcid = shopcid;
}

string ShopInfo::getProductID() const
{
    return m_productID;
}
void ShopInfo::setProductID(string& shoppid)
{
    m_productID = shoppid;
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
void ShopInfo::setPrice(int& price)
{
    m_price = price;
}
string ShopInfo::getname() const
{
    return m_name;
}
string ShopInfo::getphoneNumber() const
{
    return m_phonenumber;
}

string ShopInfo::getaddress() const
{
    return m_address;
}
