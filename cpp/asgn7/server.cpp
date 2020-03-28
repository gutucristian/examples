#include "Server.H"
#include <iostream>
#include <string>
#include "Node.H"

Server::Server() {
	//std::cout << "Run Server constructor!" << std::endl;
}

Server::~Server() {
	//std::cout << "Destroy Server with tag = " << tag << std::endl;
};

Server::Server(char tag, std::string name, std::string arguments) : Node(tag, name, arguments) {
	//std::cout << "Run Server constructor!" << std::endl;
}

void Server::print() {
	if (name == "ServerExit") {
		std::string res = std::string(1, tag) + " --> " + std::string(1, tag) + "=" + name + "()";
 		std::cout << res << std::endl;
	} else {
		std::string res = std::string(1, tag) + " --> " + std::string(1, tag) + "=" + name + "(" + arguments + ",target=" + target + ")";
 		std::cout << res << std::endl;
	}
}
