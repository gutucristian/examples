#ifndef __Schema_H
#define __Schema_H

#include <string>
#include <vector>

class Schema
{
	public:
		std::vector<std::string> schema;
		Schema();
		void loadSchema(std::string fname);		
};

#endif
