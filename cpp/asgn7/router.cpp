#include "Server.H"
#include <iostream>
#include <string>
#include "Node.H"
#include "Router.H"

Router::Router() {
	//std::cout << "Run Server constructor!" << std::endl;
}

Router::~Router() {
	//std::cout << "Destroy Server with tag = " << tag << std::endl;
};

Router::Router(char tag, std::string name, std::string arguments) : Node(tag, name, arguments) {
	//std::cout << "Run Server constructor!" << std::endl;
}

void Router::print() {
	std::string res = std::string(1, tag) + " --> " + std::string(1, tag) + "=" + name + "([" + arguments + "])";
 	std::cout << res << std::endl;
}
