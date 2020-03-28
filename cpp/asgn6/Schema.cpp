#include "Schema.H"
#include <fstream>
#include <iostream>
#include <sstream>

void Schema::loadSchema(std::string fname) {	
	std::ifstream file;
	file.open(fname);
	
	std::string line;
	getline(file, line);
	//std::cout << line << std::endl;
	std::stringstream linestream(line);
	std::string word;
	while(getline(linestream, word, ',')) {
		this->schema.push_back(word);
		//std::cout << "col: " << word << std::endl;
	}

	file.close();
}

Schema::Schema() {
	//std::cout << "constuct Schema" << std::endl;
}
