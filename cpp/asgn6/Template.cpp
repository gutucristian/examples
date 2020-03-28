#include "Template.H"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Recipient.H"
#include <algorithm>
#include <iomanip>

Template::Template(std::string fname){
	std::ifstream file;
	file.open(fname);
	std::stringstream strStream;
	strStream << file.rdbuf(); //read the file
	this->template_contents = strStream.str(); //str holds the content of the file
	//std::cout << this->template_contents << std::endl;
};

void Template::parse(Recipient r, std::string fname) {
	std::string res;
	std::stringstream strStream(this->template_contents);
	std::string word;
	for (int i = 0; strStream >> word; i++) {
		std::string edit;
    if (word[0] == '$') {
			//std::cout << "word = " << word << std::endl;
			std::string tmp = word;
			
			word.erase(std::remove_if(word.begin(), word.end(), [](char c) { return c==','||c=='.'|| c=='$'; }), word.end());
			//std::cout << "word 1= " << word << std::endl;
			std::size_t found = word.find("(");
			//std::cout << "word 2= " << word << std::endl;
	
			if (found != std::string::npos) {
				word.erase(word.find('('));
				if (word == "today") {
					std::size_t open = tmp.find("(");
					std::size_t close = tmp.find(")");
					std::string arg = tmp.substr(open+1, close-open-1);
					int nbDays = stoi(arg);
					//std::cout << "number of days = " << nbDays << std::endl;
          time_t now = time(NULL);
          struct tm* tm = localtime(&now);
          tm->tm_mday += nbDays;
          time_t later = mktime(tm);
          struct tm* then = localtime(&later);
          char buffer[80];
          strftime(buffer,sizeof(buffer),"%d/%m/%Y",then);
          std::string str(buffer);
					edit.append(str);
				} else if (word == "bold") {
					edit.append("**");
					edit.append(r.data["invoice"]);
					edit.append("**");
				} else if (word == "date") {
					edit.append(r.data["when"]);
				} else if (word == "usd") {
					edit.append(r.data["amount"]);
					edit.append("USD");
				} else if(word == "scale") {
					float fee = stoi(r.data["amount"]) * .1;
					edit.append(std::to_string(fee));
					edit.append("USD.");
				}
				res.append(edit);
				if (word == "scale")
					res.append("\n\n");
			} else {	
				if (word == "salutation") {
					res.append(edit.append(r.data["salutation"]));
				} else if(word == "fName") {
					res.append(edit.append(r.data["fName"]));
				} else if(word == "lName") {
					res.append(edit.append(r.data["lName"]));
					res.append(",\n\n");
				}
			}
		} else {
			res.append(word);
			if (word == "payment")
				res.append("\n\n");
			if (word == "yours,")
				res.append("\n\n");
		}
		res.append(" ");
	}
	
	//for (const auto &p : r.data) {
	//	std::cout << "recipient[" << p.first << "] = " << p.second << std::endl;
	//}
	std::ofstream os(fname);
	os << res;
	
	//std::cout << res << std::endl;
}
