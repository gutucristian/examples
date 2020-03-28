#ifndef __ORDER_H
#define __ORDER_H

#include <"item.H">
#include <list>

struct Order {
	string name;
	std::List<Item> items;
};

#endif
