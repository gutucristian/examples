#include <fstream>
#include "product.H"
#include "order.H"

int main() {
	using namespace std;
	ifstream dbs("products.txt");
	ProductDB theDB(dbs);
	dbs.close();

	Order order("order.txt");
	order.makeInvoice(theDB);	
	return 0;
}
