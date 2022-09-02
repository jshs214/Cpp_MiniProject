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

    string getclientID() const;     // 绊按 ID
    void setclientID(string&);
    string getName() const;     //绊按 捞抚
    void setName(string&);
    string getPhoneNumber() const;  // 傈拳锅龋
    void setPhoneNumber(int&);
    string getAddress() const;      //林家
    void setAddress(string&);  


private:
    string m_clientID;      // 绊按 ID
    string m_name;          // 绊按 捞抚
    string m_phoneNumber;   // 绊按 傈拳锅龋
    string m_address;       // 绊按 林家
    
};
#endif          // __CLIENT_H__