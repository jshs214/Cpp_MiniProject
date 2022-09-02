
#include <vector>
#include <algorithm>
#include "Client.h"
#include "Product.h"
#include "ShopInfo.h"

class ShopInfoManager {
public:

    void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // 주문하기
    {
        int shopkey;
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
        
        
        shopkey = 1000;
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

        for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)
        {
            auto sch_shopkey = (*it)->getShopkey();
            if (sch_shopkey == shopkey) {
                shopkey++;
                //cout << "[고객 ID 입력완료]"<<endl;
                break;
            }
        }

        if(cinput > 0 && pinput> 0){
        ShopInfo* newShopC = new ShopInfo(shopkey,cid, pid,stock);
        ShopInfolist.push_back(newShopC);
        }

        
         cout << "[주문 완료]" << endl;

         Sleep(1000);	//Delay 1초
    }//void add_Shoplist(vector<Client*>& clientList, vector<Product*>& productList)       // 주문하기 함수 종료
    

    void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 조회
    {
        string name;            //Client 고객명
        string phonenumber;     //  전화번호
        string address;         //  주소
        string productname;     //Product 제품명
        string producttype;  // 종류
        int price;           //  제품 가격
        int sum = 0;   //총합

        cout << LINE << endl;
        cout << "PK/ 고객 ID / 이름 / 제품코드 / 제품명 / 종류 / 가격 / 수량 / 결제가격 / 전화번호 / 주소" << endl;
        cout << LINE << endl;

        for (auto it = ShopInfolist.begin(); it != ShopInfolist.end(); ++it)    //Shoplist 벡터 검사
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
                << (*it)->getStock() << " / " <<"결제가격 : "<<sum << " / "
                <<phonenumber << " / " << address << endl;
        }
        cout << "[총 " << ShopInfolist.size() << "건의 주문이 있습니다.]" << endl;
    }//void shoplist_print(vector<Client*>& clientList, vector<Product*>& productList)     // 조회하기 함수 종료


private:
    vector<ShopInfo*> ShopInfolist;     // ShopInfo의 벡터
};


