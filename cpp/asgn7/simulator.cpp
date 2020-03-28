#include "Simulator.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include "Node.H"
#include "Buffer.H"
#include "Server.H"
#include <memory>
#include "Generator.H"
#include "Router.H"

Simulator::Simulator() {
	//std::cout << "Run Simulator constructor!" << std::endl;
}

void Simulator::read(std::string fName) {
	std::string line;
	std::ifstream file(fName);
	if(file.is_open()) {
		while(getline(file, line)) {
			if (line.find("->") != std::string::npos) {
				readLink(line);
			} else {
				readNode(line);
			}
		}
		file.close();
	} else {
		std::cout << "Unable to open file: \"" << fName << "\"" << std::endl;
	}
}

void Simulator::readNode(std::string line) {
	char tag = line[0];
	if (line.find("FIFO") != std::string::npos) {			
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> buf(new Buffer(tag, "FIFO", args));
		network.addNode(tag, std::move(buf));
	} else if (line.find("ServerExp") != std::string::npos) {
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> server(new Server(tag, "ServerExp", args));
		network.addNode(tag, std::move(server));
	} else if (line.find("ServerNormal") != std::string::npos) {
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> server(new Server(tag, "ServerNormal", args));
		network.addNode(tag, std::move(server));
	} else if (line.find("ServerCst") != std::string::npos) {
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> server(new Server(tag, "ServerCst", args));
		network.addNode(tag, std::move(server));
	} else if (line.find("Exit") != std::string::npos) {
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> server(new Server(tag, "ServerExit", args));
		network.addNode(tag, std::move(server));
	} else if (line.find("Poisson") != std::string::npos) {
		std::string args = getArguments(line, '(', ')');
		std::unique_ptr<Node> generator(new Generator(tag, "Poisson", args));
		network.addNode(tag, std::move(generator));
	} else if (line.find("Dispatch") != std::string::npos) {
		std::string args = getArguments(line, '[', ']');
		std::unique_ptr<Node> generator(new Router(tag, "Dispatch", args));
		network.addNode(tag, std::move(generator));
	} 
}

std::string Simulator::getArguments(std::string str, char delimA, char delimB) {
	std::size_t open = str.find(std::string(1, delimA)) + 1;
	std::size_t close = str.find(std::string(1, delimB));
	return str.substr(open, close-open);
}

std::string Simulator::getTarget(std::string str) {
	std::size_t open = str.find(">") + 1;
	return str.substr(open);
}

void Simulator::readLink(std::string line) {
	char tag = line[0];
	if (line.find("->") != std::string::npos) {
		std::string target = getTarget(line);
		//std::cout << "target = " << target << std::endl;
		network.getNode(tag)->target = target;
	}
}

void Simulator::print() {
	//std::cout << "print network..." << std::endl;
	for (auto it = network.nodes.begin(); it != network.nodes.end(); it++) {
		it->second->print();
	}
}

void Simulator::run() {
	//std::cout << "run simulation..." << std::endl;
	print();
}

Simulator::~Simulator() {
	//std::cout << "Destroy Simulator." << std::endl;
}
