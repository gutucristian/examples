#include "Buffer.H"
#include <string>
#include "Node.H"
#include <iostream>

void Buffer::print() {
	std::string res = std::string(1, tag) + " --> " + std::string(1, tag) + "=" + name + "(target = " + target + ")";
	std::cout << res << std::endl;
}

Buffer::Buffer() {
	//std::cout << "Run Buffer constructor!" << std::endl;
}

Buffer::~Buffer() {
	//std::cout << "Destroy Buffer with tag = " << tag << std::endl;
}

Buffer::Buffer(char tag, std::string name, std::string arguments) : Node(tag, name, arguments) {
	//std::cout << "Run Buffer constructor!" << std::endl;
}
