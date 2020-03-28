#ifndef __Buffer_H
#define __Buffer_H

#include "Node.H"
#include <string>

class Buffer: public Node {
	public:
		void print();
		Buffer();
		Buffer(char tag, std::string name, std::string arguments);
		~Buffer();
};

#endif
