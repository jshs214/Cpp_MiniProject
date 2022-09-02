#include <map>
#include "ShopInfo.h"

#include <iostream>

ShopInfo::ShopInfo(int shopkey,string shopcid, string shoppid, int sstock)
    :m_shopkey(shopkey) ,m_shopcid(shopcid), m_shoppid(shoppid), m_sstock(sstock)
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
    return m_shoppid;
}
void ShopInfo::setProductID(string& shoppid)
{
    m_shoppid = shoppid;
}
int ShopInfo::getStock() const
{
    return m_sstock;
}
void ShopInfo::setStock(int& sstock)
{
    m_sstock = sstock;
}