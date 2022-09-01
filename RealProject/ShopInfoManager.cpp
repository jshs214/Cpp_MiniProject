
#include <vector>
#include <algorithm>
#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"

class ShopInfoManager {
public:

    //void add()
    //{
    //    string shopcid;
    //    cout << "�� ID : "; cin >> shopcid;
    //    ShopInfo* newShopC = new ShopInfo(shopcid);
    //    ShopInfolist.push_back(newShopC);
    //    for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
    //        cout << s->getshopID() << endl;
    //        });
    //}

    void getClient(vector<Client*>& clientList)       //Client ���͸� ShopInfo��
    {
        string shopcid;

        cout << "�� ID : "; cin >> shopcid;
        ShopInfo* newShopC = new ShopInfo(shopcid);
        ShopInfolist.push_back(newShopC);

        for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
            cout << s->getshopID() << endl;
        });
        
            for_each(clientList.begin(), clientList.end(), [](Client* c) {
            cout << c->getclientID() << " / "
                 << c->getName() << " / "
                << c->getPhoneNumber() << " / "
                << c->getAddress() << endl;
            });
    }

    //void getClient(vector<Client*>& clientList)       //Client ���͸� ShopInfo��
    //{
    //    for_each(clientList.begin(), clientList.end(), [](Client* c) {
    //        cout << c->getclientID() << " / "
    //             << c->getName() << " / "
    //             << c->getPhoneNumber() << " / "
    //             << c->getAddress() << endl;
    //        });
    //}


private:
    vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
};


