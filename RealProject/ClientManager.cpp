#include "Client.h"
#include <iostream>
#include<vector>
#include <algorithm>

class ClientManager {
public:
	void add_Client()		// �Է�
	{
		string name;
		string clientid;
		string phonenumber;
		string address;

		system("cls");
		cout << "========================================================================" << endl;
		cout << "                           �ű� �� �������                             " << endl;
		cout << "========================================================================" << endl;
		cout << "�̸� : "; cin >> name;
		cout << "�� ID(PK) : "; cin >> clientid;
		cout << "��ȭ��ȣ : "; cin >> phonenumber;
		cout << "�ּ� : "; cin.ignore(); getline(cin, address);

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_PK = (*it)->getclientID();

			if (sch_PK == clientid) {
				while(1){
				cout << " �ߺ� id �Դϴ�. �ٽ� �Է��� �ּ��� : ";
				cin >> clientid;
					if (sch_PK != clientid)	break;
				}
			}

		}

		Client* newClient = new Client(name, clientid ,phonenumber, address);
		clientList.push_back(newClient);

		cout << "[�ű� �� ��� �Ϸ�]" << endl;

	}

	void add_client_print()		//��ȸ
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                               ��������ȸ                             " << endl;
		cout << "========================================================================" << endl;
		cout << "       �̸�     /   �� ID (PK)   /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << "========================================================================" << endl;
	
		for_each(clientList.begin(), clientList.end(), [](Client* c) {
			cout<< c->getName() << " / "
				<< c->getclientID() << " / "
				<<  c->getPhoneNumber() << " / "
				<<  c->getAddress() << endl;
			});
	}

	void search_client()		//�˻�
	{
		string input;
		int sch_num;		//�˻��� ����
		string up_data;
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                             ���� �˻�                             " << endl;
		cout << "========================================================================" << endl;
		cout << "���� �˻� : "; cin >> input;

		cout << "========================================================================" << endl;
		cout << "       �̸�      /     �� ID     /     ��ȭ��ȣ      /       �ּ�" << endl;
		cout << "========================================================================" << endl;
		
		for(auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getName();
			if (sch_name == input) {
				cout << (*it)->getName() << " / "
					<< (*it)->getclientID() << " / "
					<< (*it)->getPhoneNumber() << " / "
					<< (*it)->getAddress() << endl;
			}
		}

	}

	void delete_client()		//���� �� ID�� pkŰ��
	{
		system("cls");
		cout << "========================================================================" << endl;
		cout << "                             �� ���� ����                              " << endl;
		cout << "========================================================================" << endl;
		string input;
		cout << "������ �� ID �Է��ϼ��� : "; cin >> input;		// ���� -> �� ID�� �����ؾ���

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_ID = (*it)->getclientID();

			if (sch_ID == input) {
				clientList.erase(it);
				cout << input <<" �� ���� ������ �����Ǿ����ϴ�." << endl;
				break;
			}
		}
	}

	void update_client()	//�� ����
	{
		cout << "========================================================================" << endl;
		cout << "                             �� ���� ����                              " << endl;
		cout << "========================================================================" << endl;
		string input;	//�� ID ����
		int up_num;	// ������Ʈ���� �������� ����
		string up_data;	// ������Ʈ �� ������

		cout << "�� ID �Է� : "; cin >> input;

		for (auto it = clientList.begin(); it != clientList.end(); ++it)
		{
			auto sch_name = (*it)->getclientID();		//�Է��� �� ID �����Ͱ� ������

			if (sch_name == input) {
				cout << "1. �̸� ����  2. ��ȭ��ȣ ���� 3. �ּ� ����" << endl;
				cin >> up_num;	//������ ����

				switch (up_num)
				{
				case 1:		//�̸� ����
					cout << "������ �̸� �Է�"<<endl;		cin >> up_data;
					(*it)->setName(up_data);
					break;

				case 2:		//��ȭ��ȣ ����
					cout << "������ ��ȭ��ȣ �Է�" << endl;	cin >> up_data;
					(*it)->setPhoneNumber(up_data);
					break;

				case 3:		//�ּ� ����
					cout << "������ �ּ� �Է� : " ;	cin >> up_data;
					(*it)->setAddress(up_data);
					break;
				}
			}

		}
	}

private:
	vector<Client*>clientList;
};