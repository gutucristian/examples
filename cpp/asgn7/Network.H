#ifndef __Network_H
#define __Network_H

#include <map>
#include <string>
#include "Node.H"
#include <memory>

class Network {
	public:
		std::map<char, std::unique_ptr<Node>> nodes;
		void addNode(char tag, std::unique_ptr<Node> node);
		std::unique_ptr<Node>& getNode(char tag);
		Network();
};

#endif
