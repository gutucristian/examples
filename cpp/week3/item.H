#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <string>

struct Bottle {
	int _id;
	std::string _name;
	double _price;
};

struct Inventory {
	std::map<int, Bottle> wineInventory;
	Inventory(std::string filename);
	const Bottle& getBottle(int id) const;
	void addBottle(Bottle bottle);
};

#endif
