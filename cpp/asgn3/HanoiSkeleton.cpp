#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

struct peg {
   stack<int> discs;
   char name;
};

struct game {
	peg a;
	peg b;
	peg c;
};

void printTowerOfHanoi(int height, game hanoi) {
	peg& a = hanoi.a;
	peg& b = hanoi.b;
	peg& c = hanoi.c;
	int count = height;
	while (!a.discs.empty() or !b.discs.empty() or !c.discs.empty())  {
		if(!a.discs.empty() && count == a.discs.size()) {
			int aBack = a.discs.top();
			string digit = string(to_string(height).size() - to_string(aBack).size(), ' ') + to_string(aBack);
			string disc = string(aBack, '_') + digit + string(aBack, '_');
			int len = disc.size();
			int x = to_string(height).size();
			int rem = (height*2) + x - len;
			string res = string(rem/2, ' ') + disc + string(rem/2, ' ');
			a.discs.pop();
			cout << res;
		} else {
			int x = to_string(height).size();
			string res = string((height*2)+x, ' ');
			cout << res;
		}
		if(!b.discs.empty() && count == b.discs.size()) {
			int aBack = b.discs.top();
			string digit = string(to_string(height).size() - to_string(aBack).size(), ' ') + to_string(aBack);
			//string disc = string(aBack, '_') + to_string(aBack) + string(aBack, '_');
			string disc = string(aBack, '_') + digit + string(aBack, '_');
			int len = disc.size();
			int x = to_string(height).size();
			int rem = (height*2) + x - len;
			string res = string(rem/2, ' ') + disc + string(rem/2, ' ');
			b.discs.pop();
			cout << res;
		} else {
			int x = to_string(height).size();
			string res = string((height*2)+x, ' ');
			cout << res;
		}
		if(!c.discs.empty() && count == c.discs.size()) {
			int aBack = c.discs.top();
			string digit = string(to_string(height).size() - to_string(aBack).size(), ' ') + to_string(aBack);
			//string disc = string(aBack, '_') + to_string(aBack) + string(aBack, '_');
			string disc = string(aBack, '_') + digit + string(aBack, '_');
			int len = disc.size();
			int x = to_string(height).size();
			int rem = (height*2) + x - len;
			string res = string(rem/2, ' ') + disc + string(rem/2, ' ');
			c.discs.pop();
			cout << res;
		} else {
			int x = to_string(height).size();
			string res = string((height*2)+x, ' ');
			cout << res;
		}
		count -= 1;
		cout << endl;
	}
}

void tower(int n, int height, game& hanoi, peg& from, peg& to, peg& aux) {
	if (n > 0) {
		tower(n-1, height, hanoi, from, aux, to);

		string separator = string(height*3*3, '-');
		cout << separator << endl;
		cout << endl << "Move a disk from " << from.name << " to " << to.name << endl;

		int top = from.discs.top();
		from.discs.pop();
		to.discs.push(top);
		
		printTowerOfHanoi(height, hanoi);

		tower(n-1, height, hanoi, aux, to, from);
	}
}

void towerOfHanoiPegs(int height) {
   peg a, b, c;
   a.name = 'a';
   b.name = 'b';
   c.name = 'c';

   for (int i = height; i > 0; i--)
      a.discs.push(i);
   
	 game hanoi;
	 hanoi.a = a;
	 hanoi.b = b;
   hanoi.c = c;

   tower(height, height, hanoi, hanoi.a, hanoi.c, hanoi.b);
}

int main () {
   cout << "4 disc tower of Hanoi" << endl << endl;
   towerOfHanoiPegs(4);
   // cout << endl << endl << endl << "10 disc tower of Hanoi" << endl << endl;
   // towerOfHanoiPegs(10);
   // cout << endl << endl << endl << "15 disc tower of Hanoi" << endl << endl;
   // towerOfHanoiPegs(15);
}
