#include "Server.H"
#include <iostream>
#include <string>
#include "Node.H"
#include "Generator.H"

Generator::Generator() {
	//std::cout << "Run Server constructor!" << std::endl;
}

Generator::~Generator() {
	//std::cout << "Destroy Server with tag = " << tag << std::endl;
};

Generator::Generator(char tag, std::string name, std::string arguments) : Node(tag, name, arguments) {
	//std::cout << "Run Server constructor!" << std::endl;
}

void Generator::print() {
	std::string res = std::string(1, tag) + " --> " + std::string(1, tag) + "=" + name + "(" + arguments + ")";
 	std::cout << res << std::endl;
}
