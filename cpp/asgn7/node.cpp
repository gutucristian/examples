#include "Node.H"
#include <string>
#include <iostream>

void Node::print() {
	std::cout << "Print in node." << std::endl;
}

Node::Node() {
	//std::cout << "Run Node constructor!" << std::endl;
}

Node::Node(char tag, std::string name, std::string arguments) : tag(tag), name(name), arguments(arguments) {}

Node::~Node() {
	//std::cout << "Destroy Node with tag = " << tag << std::endl;
}
