#include "order.H"
#include <iomanip>
#include <fstream>

Order::Order(const std::string& fn) {
	std::ifstream is(fn);
	is >> _name;
	while (is) {
		LineOrder lo(is);
		_orders.push_back(lo);
	}
	is.close();
}

void Order::makeInvoice(const ProductDB& pdb) {
	using namespace std;
	cout << "Wine Inc." << endl;
	cout << "Invoice for: " << _name << endl;
	int total = 0;
	for(const LineOrder& lo: _orders) {
		if (pdb.hasProduct(lo._product)) {
			const auto& p = pdb.find(lo._product);
			auto price = lo._quantity * p._price;
			total += price;
			cout << setw(40) << p._label << " | "
					 << setw(4) << lo._quantity << " | "
					 << setw(4) << p._price << " | "
					 << setw(4) << p._price << " | "
					 << setw(5) << price << endl;
		}
	}

	cout << std::string(40+3+14+3+4, '-') << endl;
	cout << setw(40) << "Total " << " | " << setw(14)
			 << " | " << setw(5) << total << endl;
}
