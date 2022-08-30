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
    string m_name;          // �� �̸�
    string m_phoneNumber;   // �� ��ȭ��ȣ
    string m_address;       // �� �ּ�

};
#endif          // __CLIENT_H__