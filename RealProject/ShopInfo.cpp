#include <map>
#include "ShopInfo.h"

#include <iostream>

ShopInfo::ShopInfo(string shopcid, string shoppid, int sstock)
    :m_shopcid(shopcid), m_shoppid(shoppid), m_sstock(sstock)
{
}

string ShopInfo::getshopID() const
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