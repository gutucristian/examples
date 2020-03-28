#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>
#include <iostream>
#include <map>

struct Product {
	int _code;
	int _price;
	std::string _label;
	Product();
	Product(int c, int p, const std::string& lbl);
	Product(const Product& p);
	Product& operator=(const Product& p);
	Product(std::istream& is);
};

struct ProductDB {
	std::map<int, Product> _db;
	ProductDB(std::istream& is);
	bool hasProduct(int code) const;
	const Product& find(int code) const;
	int nbProducts() const;
};

#endif
