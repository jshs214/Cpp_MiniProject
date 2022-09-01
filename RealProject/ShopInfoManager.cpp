
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

    void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       //Client ���͸� ShopInfo��
    {
        string cid, pid;
        int stock;
        int cinput = 0; //��ġ�ϴ��� flag
        int pinput = 0; //��ġ�ϴ��� flag
        bool cflag = false;
        bool pflag = false;

        system("cls");
        cout << LINE << endl;
        cout << "                           �ֹ�                             " << endl;
        cout << LINE << endl;

        cout << "�� ID : "; cin >> cid;   // ClientID PK�˻縦 ���� cin
        cout << "��ǰ ID : "; cin >> pid;   // ProductID PK�˻縦 ���� pin
        cout << "������ ��ǰ ���� : "; cin >> stock;
        while (1) {
            cflag = false;
            cinput = 0;
            for (auto it = clientList.begin(); it != clientList.end(); ++it)
            {
                auto sch_cid = (*it)->getclientID();
                if (sch_cid == cid) {           // ClientID�� �Է��� id�� ������
                    cflag = true;
                    cinput++;
                    //cout << "[�� ID �Է¿Ϸ�]"<<endl;
                    break;
                }
            }
            if (cflag == true)	break;
            else
            {
                cout << "�� ID�� �����ϴ�. ���Է� ���ּ��� (���� 0) : ";
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
                if (sch_pid == pid) {           // ClientID�� �Է��� id�� ������
                    pflag = true;
                    pinput++;
                    //cout << "[��ǰ ID �Է¿Ϸ�]" << endl;
                    break;
                }
            }
            if (pflag == true)	break;
            else
            {
                cout << "��ǰ ID�� �����ϴ�. ���Է� ���ּ��� (���� 0) :";
                cin >> pid;
            }
            if(pid == "0") return;
        }


        /*for (auto it = clientList.begin(); it != clientList.end(); ++it)
        {
            auto sch_cid = (*it)->getclientID();
            if (sch_cid == cid) {
                cout << "�� ID ��ġ" ;
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
        //        cout << "��ǰ ID ��ġ" ;
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
         cout << "[�ֹ� �Ϸ�]" << endl;

         Sleep(1000);	//Delay 1��
    }

    void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // �ֹ�
    {
        for_each(ShopInfolist.begin(), ShopInfolist.end(), [](ShopInfo* s) {
            cout << s->getshopID() << " / " << s->getProductID() << " / " << s->getStock() << endl;
            });
    }


private:
    vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
};


