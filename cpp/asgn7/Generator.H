#ifndef __Generator_H
#define __Generator_H

#include "Node.H"
#include <string>

class Generator: public Node {
	public:
		void print();
		Generator();
		Generator(char tag, std::string name, std::string arguments);
		~Generator();
};

#endif
