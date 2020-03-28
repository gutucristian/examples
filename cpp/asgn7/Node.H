#ifndef __Node_H
#define __Node_H

#include <string>
#include <vector>

class Node {
	public:
		std::string name;
		std::string arguments;
		char tag;
		std::string target;
		virtual void print();
		Node();
		Node(char tag, std::string name, std::string arguments);
		virtual ~Node();
};

#endif
