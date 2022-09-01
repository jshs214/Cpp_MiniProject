#include <map>
#include "ShopInfo.h"

#include <iostream>

ShopInfo::ShopInfo(string shopcid)
    :m_shopcid(shopcid)
{
}

string ShopInfo::getshopID() const
{
    return m_shopcid;
}

void ShopInfo::setclientID(string& m_shopcid)
{
    m_shopcid = m_shopcid;
}


