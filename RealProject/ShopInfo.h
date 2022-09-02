#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__
#include "Client.h"
#include "Product.h"
#include <iostream>

using namespace std;

class ShopInfo {
public:
    ShopInfo(int = 1001, string = "",string = "", int = 0);

    int getShopkey() const;
    void setShopkey(int&);
    string getclientID() const;     // °í°´ ID
    void setclientID(string&);
    string getProductID() const;    // Á¦Ç° ID
    void setProductID(string&);
    int getStock() const;
    void setStock(int& );
private:
    //void add_Shoplist(vector<Client*>, vector<Product*>);

    int m_shopkey;
    string m_shopcid;
    string m_shoppid;
    int m_sstock;
};
#endif          // __CLIENT_H__