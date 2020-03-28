#include "model.hpp"

// Implementations are provided directly in model.hpp

//namespace SVG {
	//ostream& operator<<(ostream& os, shared_ptr<Shape> s) {
	//	return (*s).print(os);
	//}

	//ostream& operator<<(ostream& os, shared_ptr<Model> m){
	//	return (*m).print(os);
	//};

//}

//Rect::ostream& print(ostream& os) const {
//	return os << "<rect x=\"" << x << "\" y=\"" 
//						<< y << "\" width=\"" << width
//						<< "\" height=" << height << "\" />";
//}
//	
//Line::ostream& print(ostream& os) const {
//	return os << "<line x1=\"" << x1 << "\" y1=\"" 
//						<< y1 << "\" x2=\"" << x2
//						<< "\" y2=" << y2 << "\" />";
//}
//
//Circle::ostream& print(ostream& os) const {
//	return os << "<line x=\"" << x << "\" y=\"" 
//						<< y << "\" r=\"" << r << "\" />";
//}

//Group::ostream& print(ostream& os) const {
//	os << "<group>" << endl;
//	for (auto shape: shapes) {
//		os << shape << endl;
//	}
//	os << "</group>" << endl;
//}

//void Group::add(shared_ptr<Shape> shape) { 
//	shapes.push_back(shape);
//}

//void Model::add(shared_ptr<Group> group) { 	
//	groups.push_back(group);
//}
//
//void Model::add(shared_ptr<Shape> shape) { shapes.push_back(shape);}
//
//Model::ostream& operator<<(ostream& os, const Model& m) {
//	os << "<group>" << endl;
//	for (auto group: m.groups) {
//		os << group << endl;
//	}
//	for (auto shape: m.shapes) {
//		os << shape << endl;
//	}
//	os << "</group>" << endl;
//	return os;
//}
//
