#include <iostream>
#include <iomanip>
#include "Database.H"
#include "Template.H"

using namespace std;

int main(int argc,char* argv[])
{
	Database x("victims.csv");
	Template t("template.md");
	for (int i = 1; i <= x.data.size(); i++) {
		std::string fname = "letter_";
		fname.append(std::to_string(i));
		fname.append(".txt");
		t.parse(x.data[i-1], fname);
	}
	return 0;
}
