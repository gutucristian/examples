#include <iostream>
#include <vector>
using namespace std;

class A {
public:
		A() {};
    virtual void foo() {
        cout << "A" << endl;
    }
};

class B : public A {
public:	
		B() {};
    void foo() {
        cout << "B" << endl;
    }
};

int main() {
		vector<A*> v;
		A *a = new A();
		v.push_back(a);
		B *b = new B();
		v.push_back(b);
		for (auto e: v) {
			(*e).foo();
		}
    return 0;
}
