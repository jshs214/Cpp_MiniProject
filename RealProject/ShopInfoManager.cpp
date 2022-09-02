
#include <vector>
#include <algorithm>
#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"

class ShopInfoManager {
public:

    void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // �ֹ��ϱ�
    {
        int shopkey;
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
        
        
        shopkey = 1000;
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

        for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
        {
            auto sch_shopkey = (*it)->getShopkey();
            if (sch_shopkey == shopkey) {
                shopkey++;
                //cout << "[�� ID �Է¿Ϸ�]"<<endl;
                break;
            }
        }

        if(cinput > 0 && pinput> 0){
        ShopInfo* newShopC = new ShopInfo(shopkey,cid, pid,stock);
        ShopInfolist.push_back(newShopC);
        }

        
         cout << "[�ֹ� �Ϸ�]" << endl;

         Sleep(1000);	//Delay 1��
    }//void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // �ֹ��ϱ� �Լ� ����
    

    void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // ��ȸ
    {
        string name;            //Client ����
        string phonenumber;     //  ��ȭ��ȣ
        string address;         //  �ּ�
        string productname;     //Product ��ǰ��
        string producttype;  // ����
        int price;           //  ��ǰ ����
        int sum = 0;   //����

        cout << LINE << endl;
        cout << "PK/ �� ID / �̸� / ��ǰ�ڵ� / ��ǰ�� / ���� / ���� / ���� / �������� / ��ȭ��ȣ / �ּ�" << endl;
        cout << LINE << endl;

        for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist ���� �˻�
        {

            for (auto cit = clientList.begin(); cit != clientList.end(); ++cit)
            {
                if ((*it)->getclientID() == (*cit)->getclientID())
                {
                    name = (*cit)->getName();
                    phonenumber = (*cit)->getPhoneNumber();
                    address = (*cit)->getAddress();
                    break;
                }
            }
            for (auto pit = productList.begin(); pit != productList.end(); ++pit)
            {
                if ( (*it)->getProductID() == (*pit)->getProductID() )
                {
                    productname = (*pit)->getProductName();
                    producttype = (*pit)->getProductType();
                    price = (*pit)->getPrice();
                    sum = price * (*it)->getStock();
                    break;
                }
            }
           
            cout << "NO." << (*it)->getShopkey() << " / " << (*it)->getclientID() << " / " << name << " / " << (*it)->getProductID() << " / "
                <<productname << " / " << producttype << " / " << price << " / "
                << (*it)->getStock() << " / " <<"�������� : "<<sum << " / "
                <<phonenumber << " / " << address << endl;
        }
        cout << "[�� " << ShopInfolist.size() << "���� �ֹ��� �ֽ��ϴ�.]" << endl;
    }//void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // ��ȸ�ϱ� �Լ� ����


private:
    vector<ShopInfo*> ShopInfolist;     // ShopInfo�� ����
};


