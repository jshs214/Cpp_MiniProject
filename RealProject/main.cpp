#include "Client.h"
#include "Product.h"
#include <vector>
#include <algorithm>
int main()
{
	cout << "========================================================================" << endl;
	cout << "                           상품 관리 프로그램                         " << endl;
	cout << "                           1. 고객 정보 관리                         " << endl;
	cout << "                           2. 상품 정보 관리                         " << endl;
	cout << "                           3. 쇼핑 정보 관리                         " << endl;
	cout << "                        몇번을 입력 하시겠습니까 ?                         " << endl;
	cout << "========================================================================" << endl;
	vector<Client*> clientList;
	vector<Product*> productList;

	Client* client1 = new Client("홍", "01022426950", "안산시");
	Product* product1 = new Product(1178465412, "임플란트", 716200);

	clientList.push_back(client1);
	productList.push_back(product1);

	for_each(clientList.begin(), clientList.end(), [](Client* c) {
		cout << c->getName() << " : " << c->getPhoneNumber()<<"   " << c->getAddress() << endl;
		});

	for_each(productList.begin(), productList.end(), [](Product* p) {
		cout << "상품코드 : " << p->getProductID()<<" 상품 명 : " << p->getProductName() << " 가격 : " << p->getPrice() << endl;
		});

	return 0;
}