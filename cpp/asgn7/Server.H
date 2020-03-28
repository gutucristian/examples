#ifndef __Server_H
#define __Server_H

#include "Node.H"
#include <string>

class Server: public Node {
	public:
		void print();
		Server();
		Server(char tag, std::string name, std::string arguments);
		~Server();
};

#endif
