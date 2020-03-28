#ifndef __Template_H
#define __Template_H

#include <string>
#include "Recipient.H"

class Template
{
	public:
		std::string template_contents;
		Template(std::string fname);
		void parse(Recipient r, std::string fname);
};

#endif
