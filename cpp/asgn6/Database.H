#ifndef __Database_H
#define __Database_H

#include "Recipient.H"
#include "Schema.H"
#include <string>
#include <vector>

class Database
{
	public:
		Schema x;
		std::string fname;
		std::vector<Recipient> data;

		Database(std::string fname);
		void populate();
};

#endif
