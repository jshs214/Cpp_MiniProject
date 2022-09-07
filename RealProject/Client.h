#ifndef __CLIENT_H__
#define __CLIENT_H__
#include <iostream>
#include<string>
#include<Windows.h>
#include "Line.h"

using namespace std;
/**
* 고객정보의 데이터를 관리하는 클래스
* @author 홍성주
*/
class Client {
public:
    
    Client(string = "", string ="", string = "", string = "");
    // name, clientID, phoneNumber, address

    string getclientID()const;
    void setclientID(string&);
    string getName() const;
    void setName(string&);
    string getPhoneNumber() const;
    void setPhoneNumber(string &);
    string getAddress() const;
    void setAddress(string&);  


private:
    string m_clientID;      // 고객 ID
    string m_name;          // 고객 이름
    string m_phoneNumber;   // 고객 전화번호
    string m_address;       // 고객 주소
    
};
#endif          // __CLIENT_H__