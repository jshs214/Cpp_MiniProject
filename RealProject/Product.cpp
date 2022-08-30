#include "Product.h"

#include<iostream>

using namespace std;

Product::Product(int productID, string productName, int price, int stock,string producttype)
	: m_productID(productID), m_productName(productName), m_price(price), m_stock(stock), m_productType(producttype)
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
int Product::getStock() const
{
	return m_stock;
}
void Product::setStock(int& stock)
{
	m_stock = stock;
}
string Product::getProductType() const
{
	return m_productType;
}
void Product::setProductType(string& productType)
{
	m_productType=productType;
}
