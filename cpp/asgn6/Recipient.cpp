#include "Recipient.H"
#include <map>
#include <string>

Recipient::Recipient(const Schema& s) {
	for (auto key: s.schema) {
		this->data.insert(std::pair<std::string, std::string>(key, ""));
	}
}
