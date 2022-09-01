#ifndef __SHOPINFO_H__
#define __SHOPINFO_H__
#include "Client.h"
#include "Product.h"
#include <iostream>

using namespace std;

class ShopInfo {
public:
    ShopInfo(string = "");

    string getshopID() const;     // °í°´ ID
    void setclientID(string&);
    
private:
    //void getClient(vector<Client*>);

    string m_shopcid;

};
#endif          // __CLIENT_H__