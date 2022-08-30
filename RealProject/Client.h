#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <iostream>

using namespace std;

class Client {
public:
    Client(string = "", string = "", string = "");

    string getName() const;
    void setName(string&);
    string getPhoneNumber() const;
    void setPhoneNumber(string&);
    string getAddress() const;
    void setAddress(string&);

private:
    string m_name;          // 绊按 捞抚
    string m_phoneNumber;   // 绊按 傈拳锅龋
    string m_address;       // 绊按 林家

};
#endif          // __CLIENT_H__