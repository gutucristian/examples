#include <iostream>
#include <list>
#include <array>
#include <stack>
#include <memory>


// The Vertex, Edge and Graph ADT are defined below. 
// The ??? are placeholders. Your first task is to decide
// what should be used to get real types for your C++ 
// implementation.

struct Edge;
struct Vertex {
   int                               _id;
   std::list<Vertex>                   _adj;
   Vertex(int id) { _id = id;}
   ~Vertex() {
      std::cout << "Vertex(" << _id << ") dying" << std::endl;
   }
};

// Note that Edge inherits from enable_shared in case 
// You find this useful. You can easily create such instances of 
// shareable edges with a call to the STL convenience function
// make_shared<T> (https://en.cppreference.com/w/cpp/memory/shared_ptr/make_shared)
// that allocates (on the heap) an instance of type T 
// (and calls its constructor)
// Whether you want to use this or not is completely up to you!

struct Edge : std::enable_shared_from_this<Edge> {
   std::array<Vertex,2> _v;
   Edge(Vertex v1,Vertex v2) {
      _v[0] = v1;
      _v[1] = v2;
   }
   std::shared_ptr<Edge> getShared() { return shared_from_this();}
   ~Edge() {
      auto v0 = _v[0],v1 = _v[1];
      std::cout << "Edge(" << v0->_id << "," << v1->_id << ") dying"
                << std::endl;
   }
};
   
struct Graph {
   std::list<Vertex> _vertices;
   std::list<Edge>   _edges;
};

// Implement the addVertex function for the graph ADT.
// You must select a prototype compatible with the test program.
void addVertex(Graph& g, int i) {
	Vertex v(i);
	g._vertices.push_back(v);
}


// Implement the addEdge function for the graph ADT.
// You must select a prototype compatible with the test program.
void addEdge(Graph& g, int e1, int e2) {
	auto l1_front = g._vertices.begin();
	std::advance(l_front, e1);

	auto l2_front = g._vertices.begin();
	std::advance(l2_front, e2);

	Edge e(*l1_front, *l2_front);

	g._edges.push_back(e);
}


// The printGraph function of the ADT is *given* to you.
// Once your ADT is correctly implemented, it should be capable
// of printing the graph created by the test program.

void printGraph(const Graph& g)
{
   using namespace std;
   for(const auto&  v : g._vertices) {
      cout << v->_id << ":\t";
      for(const auto& we : v->_adj) {
         auto e = we.lock();
         cout << "edge(" << e->_v[0]->_id << "," << e->_v[1]->_id << ") ";
      }
      cout << endl;
   }
}

// THis is a minimalistic test program that creates a tiny graph
// And prints it. 
// If the ADT is implemented correctly, this should NOT leak any 
// memory. 

int main() {
   Graph g;
   for(int i=0;i<=5;i++) addVertex(g,i);
   addEdge(g,0,1);
   addEdge(g,1,2);
   addEdge(g,2,3);
   addEdge(g,3,4);
   addEdge(g,4,5);
   addEdge(g,5,0);
   addEdge(g,0,3);

   printGraph(g);   

	 

   return 0;
}
