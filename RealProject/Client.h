#ifndef __CLIENT_H__
#define __CLIENT_H__
#include <iostream>
#include<string>
#include<Windows.h>
#include "Line.h"

using namespace std;
/**
* �������� �����͸� �����ϴ� Ŭ����
* @author ȫ����
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
    string m_clientID;      // �� ID
    string m_name;          // �� �̸�
    string m_phoneNumber;   // �� ��ȭ��ȣ
    string m_address;       // �� �ּ�
    
};
#endif          // __CLIENT_H__