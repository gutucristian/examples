#include "product.H"

Product::Product() { _code = -1;}

Product::Product(int c, int p, const std::string& lbl)
	: _code(c), _price(p), _label(lbl) {}

Product::Product(const Product& p)
	: _code(p._code), _price(p._price), _label(p._label) {}

Product& Product::operator=(const Product& p) {
	_code = p._code;
	_price = p._price;
	_label = p._label;
	return *this;
}

Product::Product(std::istream& is) {
	is >> _code >> _price >> _label;
}

ProductDB::ProductDB(std::istream& is) {
	using namespace std;
	while (is) {
		Product p(is);
		if (p._code != -1)
			_db[p._code] = p;
	}
}

bool ProductDB::hasProduct(int code) const {
	auto it = _db.find(code);
	return it != _db.end();
}

const Product& ProductDB::find(int code) const {
	auto it = _db.find(code);
	return it->second;
}

int ProductDB::nbProducts() const {
	return _db.size();
}
