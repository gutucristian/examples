#include "Database.H"
#include "Schema.H"
#include <string>
#include "Recipient.H"
#include <iostream>
#include <fstream>
#include <sstream>

Database::Database(std::string fname) {
	this->fname = fname;
	this->x.loadSchema(fname);
	//for (auto it = this->x.schema.begin(); it != this->x.schema.end(); ++it) {
	//	std::cout << *it << std::endl;
	//}
	this->populate();
}

void Database::populate() {
	std::ifstream file;
	file.open(this->fname);
	
	bool first = true;	

	// skip the first line which is the csv schema
	std::string line;

	// iterate through csv lines
	while (getline(file, line)) {
		// iterate through comma separated values on line
		if (first) {
			first = !first;
			continue;
		}
		
		std::stringstream linestream(line);
		std::string word;
		
		int i = 0;		
		Recipient recipient(this->x);

		while(getline(linestream, word, ',')) {
			//std::cout << "populate " << this->x.schema[i] << std::endl;
			recipient.data[this->x.schema[i]] = word;
			++i;
		}

		this->data.push_back(recipient);
	}
		
	//for (auto i: this->data) {
	//	for (const auto &p : i.data) {
	//		std::cout << "recipient[" << p.first << "] = " << p.second << std::endl;
	//	}
	//}

	file.close();
}
