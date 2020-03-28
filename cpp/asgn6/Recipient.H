#ifndef __Recipient_H
#define __Recipient_H

#include <map>
#include <string>
#include "Schema.H"

class Recipient
{
	public:
		std::map<std::string, std::string> data;
		Recipient(const Schema& schema);
};

#endif
