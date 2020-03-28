#ifndef __Router_H
#define __Router_H

#include "Node.H"
#include <string>

class Router: public Node {
	public:
		void print();
		Router();
		Router(char tag, std::string name, std::string arguments);
		~Router();
};

#endif
