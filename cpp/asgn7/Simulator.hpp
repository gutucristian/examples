#ifndef __SIMULATOR_H
#define __SIMULATOR_H

#include <string>
#include "Network.H"

// Write the specification of your simulator class here.
class Simulator {
	public:
		Network network;
		void read(std::string fName);
		void run();
		void readNode(std::string line);
		void readLink(std::string line);
		std::string getTarget(std::string str);
		std::string getArguments(std::string str, char delimA, char delimB);
		void print();
		Simulator();
		~Simulator();
};

#endif
