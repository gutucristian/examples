#include <iostream>
#include <map>

class Mammal {
	public:
 		std::string name;
		std::map<std::string, Mammal> mammals;
		Mammal() {}
		Mammal(std::string name) : name(name) {}
		virtual void print() {
			std::cout << "I (" << this << ") am a mammal." << std::endl;
		}
		void foo(Mammal& m) {
			std::cout << "Inside foo function. name = " << name << std::endl;
		}
};

class Human : public Mammal {
	public:
		Human(std::string name) : Mammal(name) {}
		void print() {
			std::cout << "I (" << this << ") am a human." << std::endl;
		}
};

Mammal bar() {
	Mammal m("whiskeyjack");
	m.mammals["vodkalarry"] = m;
	return m;
}

int main() {
	//Human h("charlie");
	Mammal tmp = bar();
	//auto tmp = m.mammals["vodkalarry"];
	std::cout << tmp.mammals["vodkalarry"].name << std::endl;
	return 0;	
}
