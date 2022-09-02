#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<Windows.h>
#include "Line.h"
using namespace std;

class Client {
public:
    Client(string = "", string ="", string = "", string = "");

    string getclientID() const;     // �� ID
    void setclientID(string&);
    string getName() const;     //�� �̸�
    void setName(string&);
    string getPhoneNumber() const;  // ��ȭ��ȣ
    void setPhoneNumber(int&);
    string getAddress() const;      //�ּ�
    void setAddress(string&);  


private:
    string m_clientID;      // �� ID
    string m_name;          // �� �̸�
    string m_phoneNumber;   // �� ��ȭ��ȣ
    string m_address;       // �� �ּ�
    
};
#endif          // __CLIENT_H__