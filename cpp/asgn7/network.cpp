#include "Network.H"
#include <iostream>
#include <memory>

Network::Network() {
	//std::cout << "Run Network constructor!" << std::endl;
}

void Network::addNode(char tag, std::unique_ptr<Node> node) {
	//std::cout << "add node with tag = " << node.tag << std::endl;
	nodes[tag] = std::move(node);
}

std::unique_ptr<Node>& Network::getNode(char tag) {
	return nodes[tag];
}
