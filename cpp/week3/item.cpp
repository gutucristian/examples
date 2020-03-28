#include "product.H"

Inventory::Inventory(string filename) {
	ifstream input(filename);
	while (input) {
		int id;
		string name;
		double price;
		input >> id >> price >> name;
		addBottle(Bottle(id, price, name));
	}
}

Bottle::Bottle(int id, double price, string name) {
	_id = id;
	_price = price;
	_name = name;
};
