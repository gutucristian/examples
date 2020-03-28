#ifndef __MODEL_H
#define __MODEL_H

#include <memory>
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

namespace SVG {
	using namespace std;

	class Shape {
		public:
			virtual ostream& print(ostream& os) const = 0;
			virtual shared_ptr<Shape> translate(int x, int y) = 0;
			virtual shared_ptr<Shape> scale(int factor)= 0;
			virtual void move(int x, int y) = 0;
			//virtual ~Shape();
	};

	class Rect: public Shape {
		public:
			ostream& print(ostream& os) const {
				return os << "<rect x=\"" << x << "\" y=\"" 
									<< y << "\" width=\"" << width
									<< "\" height=" << height << "\" />";
			}
		public:
			int x;
			int y;
			int width;
			int height;
			Rect(int x, int y, int w, int h) : x(x), y(y), width(w), height(h) {};
			shared_ptr<Shape> translate(int x1, int y1) {
				return shared_ptr<Rect>(new Rect(x + x1, y + y1, width, height));
			}
			shared_ptr<Shape> scale(int factor) {
				return shared_ptr<Rect>(new Rect(x, y, width*factor, height*factor));
			}
			void move(int dx, int dy) {
				x += dx;
				y += dy;
			}
	};

	class Line: public Shape {
		public:
			ostream& print(ostream& os) const {
				return os << "<line x1=\"" << x1 << "\" y1=\"" 
									<< y1 << "\" x2=\"" << x2
									<< "\" y2=\"" << y2 << "\" />";
			}
		public:
			int x1;
			int y1;
			int x2;
			int y2;
			Line(int x1, int y1, int x2, int y2) : x1(x1), y1(y1), x2(x2), y2(y2) {};
			shared_ptr<Shape> translate(int dx, int dy) {
				return shared_ptr<Line>(new Line(x1+dx, y1+dy, x2+dx, y2+dy));
			}
			shared_ptr<Shape> scale(int factor) {
				return shared_ptr<Line>(new Line(x1, y1, x2*factor, y2*factor));
			}
			void move(int dx, int dy) {
				x1 += dx;
				y1 += dy;
				x2 += dx;
				y2 += dy;
			}
	};

	class Circle: public Shape {
		public:
			ostream& print(ostream& os) const {
				return os << "<circle x=\"" << x << "\" y=\"" 
									<< y << "\" r=\"" << r << "\" />";
			}
		public:
			int x;
			int y;
			int r;
			Circle(int x, int y, int r) : x(x), y(y), r(r) {};
			shared_ptr<Shape> translate(int dx, int dy) {
				return shared_ptr<Circle>(new Circle(x+dx, y+dy, r));
			}
			shared_ptr<Shape> scale(int factor) {
				return shared_ptr<Circle>(new Circle(x, y, r*factor));
			}
			void move(int dx, int dy) {
				x += dx;
				y += dy;
			}
	};

	class Group {
		public:
			list<shared_ptr<Shape>> shapes;
			ostream& print(ostream& os) const {
				os << "<group>" << endl;
				for (auto shape: shapes) {
					//os << shape;
					(*shape).print(os);
					cout << endl;
				}
				os << "</group>" << endl;
				return os;
			}
		public:
			void add(shared_ptr<Shape> shape) {
				shapes.push_back(shape);
			}
	};

	class Model {
		public:
			list<shared_ptr<Group>> groups;
			list<shared_ptr<Shape>> shapes;
			ostream& print(ostream& os) const {
				for (auto group: groups) {
					//os << group;
					(*group).print(os);
				}
				for (auto shape: shapes) {
					//os << shape;
					(*shape).print(os);
				}
				cout << endl;
				return os;
			}
		public:
			const string name;
			typedef std::shared_ptr<Model> Ptr;
			Model(const string& name) : name(name) {};
			void add(shared_ptr<Group> group) {
				groups.push_back(group);
			}
			void add(shared_ptr<Shape> shape) { 
				shapes.push_back(shape);
			}
	};

	//ostream& operator<<(ostream& os, Group& g) {
	//	return g.print(os);
	//}
	//
	//ostream& operator<<(ostream& os, shared_ptr<Group> g) {
	//	return (*g).print(os);
	//}

	//inline ostream& operator<<(ostream& os, shared_ptr<Shape> s) {
	//	return (*s).print(os);
	//}

	inline shared_ptr<Model> translate(shared_ptr<Model>& m, int x, int y) {
		auto res = shared_ptr<Model>(new Model("silly"));
		for (auto group: (*m).groups) {
			auto g = shared_ptr<Group>(new Group());
			for (auto shape: (*group).shapes) {
				(*g).add((*shape).translate(x, y));
			}
			(*res).add(g);
		}
		for (auto shape: (*m).shapes) {
			(*res).add((*shape).translate(x, y));
		}
		return res;
	}

	inline shared_ptr<Model> scale(shared_ptr<Model>& m, int factor) {
		auto res = shared_ptr<Model>(new Model("silly"));
		for (auto group: (*m).groups) {
			auto g = shared_ptr<Group>(new Group());
			for (auto shape: (*group).shapes) {
				(*g).add((*shape).scale(factor));
			}
			(*res).add(g);
		}
		for (auto shape: (*m).shapes) {
			(*res).add((*shape).scale(factor));
		}
		return res;
	}

	inline void move(shared_ptr<Group>& group, int dx, int dy) {
		for (auto shape: (*group).shapes) {
			(*shape).move(dx, dy);
		}
	}

	inline ostream& operator<<(ostream& os, shared_ptr<Model> m){
		return (*m).print(os);
	};

	inline shared_ptr<Model> createModel(const string& n) {
  	return shared_ptr<Model>(new Model(n));
	}
}

#endif
