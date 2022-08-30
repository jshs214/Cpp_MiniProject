#include "Product.h"

#include<iostream>

using namespace std;

Product::Product(int productID, string productName, int price)
	: m_productID(productID), m_productName(productName), m_price(price)
{
}

int Product::getProductID() const
{
	return m_productID;
}
void Product::setProductID(int& productID)
{
	m_productID = productID;
}
string Product::getProductName() const
{
	return m_productName;
}
void Product::setProductName(string& productName)
{
	m_productName = productName;
}
int Product::getPrice() const
{
	return m_price;
}
void Product::setPrice(int& price)
{
	m_price = price;
}