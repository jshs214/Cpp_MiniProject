
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
    //    cout << "고객 ID : "; cin >> shopcid;
    //    ShopInfo* newShopC = new ShopInfo(shopcid);
    //    ShopInfolist.push_back(newShopC);
    //    for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
    //        cout << s->getshopID() << endl;
    //        });
    //}

    void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       //Client 벡터를 ShopInfo로
    {
        string cid, pid;
        int stock;
        int cinput = 0; //일치하는지 flag
        int pinput = 0; //일치하는지 flag
        bool cflag = false;
        bool pflag = false;

        system("cls");
        cout << LINE << endl;
        cout << "                           주문                             " << endl;
        cout << LINE << endl;

        cout << "고객 ID : "; cin >> cid;   // ClientID PK검사를 위한 cin
        cout << "제품 ID : "; cin >> pid;   // ProductID PK검사를 위한 pin
        cout << "구매할 제품 개수 : "; cin >> stock;
        while (1) {
            cflag = false;
            cinput = 0;
            for (auto it = clientList.begin(); it != clientList.end(); ++it)
            {
                auto sch_cid = (*it)->getclientID();
                if (sch_cid == cid) {           // ClientID와 입력한 id가 같으면
                    cflag = true;
                    cinput++;
                    //cout << "[고객 ID 입력완료]"<<endl;
                    break;
                }
            }
            if (cflag == true)	break;
            else
            {
                cout << "고객 ID가 없습니다. 재입력 해주세요 (종료 0) : ";
                cin >> cid;
            }

            if (cid == "0")    return;
        }

        while (1) {
            pflag = false;
            pinput = 0;
            for (auto it = productList.begin(); it != productList.end(); ++it)
            {
                auto sch_pid = (*it)->getProductID();
                if (sch_pid == pid) {           // ClientID와 입력한 id가 같으면
                    pflag = true;
                    pinput++;
                    //cout << "[제품 ID 입력완료]" << endl;
                    break;
                }
            }
            if (pflag == true)	break;
            else
            {
                cout << "제품 ID가 없습니다. 재입력 해주세요 (종료 0) :";
                cin >> pid;
            }
            if(pid == "0") return;
        }


        /*for (auto it = clientList.begin(); it != clientList.end(); ++it)
        {
            auto sch_cid = (*it)->getclientID();
            if (sch_cid == cid) {
                cout << "고객 ID 일치" ;
                cout << (*it)->getclientID() << " / "
                    << (*it)->getName() << " / "
                    << (*it)->getPhoneNumber() << " / "
                    << (*it)->getAddress() << endl;
            }
        }*/
        //for (auto it = productList.begin(); it != productList.end(); ++it)
        //{
        //    auto sch_pid = (*it)->getProductID();
        //    if (sch_pid == pid) {
        //        cout << "제품 ID 일치" ;
        //        cout << (*it)->getProductID() << " / "
        //            << (*it)->getPrice() << " / "
        //            << (*it)->getStock() << " / "<< endl;
        //    }
        //}
        if(cinput > 0 && pinput> 0){
        ShopInfo* newShopC = new ShopInfo(cid, pid,stock);
        ShopInfolist.push_back(newShopC);
        }

        for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
             cout << s->getshopID() <<" / " << s->getProductID()<< " / " << s->getStock() <<endl;
        }); 
         cout << "[주문 완료]" << endl;

         Sleep(1000);	//Delay 1초
    }

    void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 주문
    {
        for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
            cout << s->getshopID() << " / " << s->getProductID() << " / " << s->getStock() << endl;
            });
    }


private:
    vector<ShopInfo*> ShopInfolist;     // ShopInfo의 벡터
};


