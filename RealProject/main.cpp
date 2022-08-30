#include "Client.h"
#include "Product.h"
#include <vector>
#include <algorithm>
int main()
{
	cout << "========================================================================" << endl;
	cout << "                           ��ǰ ���� ���α׷�                         " << endl;
	cout << "                           1. �� ���� ����                         " << endl;
	cout << "                           2. ��ǰ ���� ����                         " << endl;
	cout << "                           3. ���� ���� ����                         " << endl;
	cout << "                        ����� �Է� �Ͻðڽ��ϱ� ?                         " << endl;
	cout << "========================================================================" << endl;
	vector<Client*> clientList;
	vector<Product*> productList;

	Client* client1 = new Client("ȫ", "01022426950", "�Ȼ��");
	Product* product1 = new Product(1178465412, "���ö�Ʈ", 716200);

	clientList.push_back(client1);
	productList.push_back(product1);

	for_each(clientList.begin(), clientList.end(), [](Client* c) {
		cout << c->getName() << " : " << c->getPhoneNumber()<<"   " << c->getAddress() << endl;
		});

	for_each(productList.begin(), productList.end(), [](Product* p) {
		cout << "��ǰ�ڵ� : " << p->getProductID()<<" ��ǰ �� : " << p->getProductName() << " ���� : " << p->getPrice() << endl;
		});

	return 0;
}