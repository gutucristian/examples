#include <iostream>
#include <set>
#include <list>
#include <array>
#include <vector>
#include <memory>
#include <functional>
#include <algorithm>

struct Edge;
struct Vertex {
   int                               _id;
   std::list<std::weak_ptr<Edge>>   _adj;
   Vertex(int id) { _id = id;}
   ~Vertex() {
      std::cout << "Vertex(" << _id << ") dying" << std::endl;
   }
};

struct Edge : std::enable_shared_from_this<Edge> {
   std::array<std::shared_ptr<Vertex>,2> _v;
   Edge(std::shared_ptr<Vertex> v1,std::shared_ptr<Vertex> v2) {
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
   std::list<std::shared_ptr<Vertex>> _vertices;
   std::list<std::shared_ptr<Edge>>   _edges;
};

auto findVertex(const Graph& g,int v1) {
   auto v1Ptr = std::find_if(g._vertices.begin(),
                             g._vertices.end(),
                             [v1](const std::shared_ptr<Vertex>& v) {
                                return v->_id == v1;
                             });
   return v1Ptr;
}

std::shared_ptr<Vertex> addVertex(Graph& g,int id) {
   auto v = std::make_shared<Vertex>(id);
   g._vertices.push_back(v);
   return v;
}

void addEdge(Graph& g,int v1,int v2) {
   auto v1Ptr = findVertex(g,v1);
   auto v2Ptr = findVertex(g,v2);
   if (v1Ptr != g._vertices.end() && v2Ptr != g._vertices.end()) {
      auto e = std::make_shared<Edge>(*v1Ptr,*v2Ptr);
      g._edges.push_back(e);
      (*v1Ptr)->_adj.push_back(e);
      (*v2Ptr)->_adj.push_back(e);
   }
}


void printGraph(const Graph& g)
{
   using namespace std;
   for(const auto&  v : g._vertices) {
      cout << v->_id << "(" << v->_adj.size() <<  ") " << endl;
      for(const auto& we : v->_adj) {
         auto e = we.lock();
         cout << "\tedge(" << e->_v[0]->_id << "," << e->_v[1]->_id << ")"
                   << endl;           
      }
   }
   cout << endl;

   for(const auto&  e : g._edges)
      cout << "edge(" << e->_v[0]->_id << "," << e->_v[1]->_id << ")"
                << endl;  
}

// TODO: Implement the findCycles function so that the test program below
// can run with no modifications whatsoever.
template<typename Func>
void findCycles(Graph& g, int v, Func f) {
	using namespace std;
	set<list<int>> cycles;
	int graph[7][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 0}, {0, 3}};

  function<void(int (&)[7][2], vector<int>&, set<list<int>>&)> findNewCycles = [&] (int (&a)[7][2], vector<int> &path, set<list<int>> &cycles) {
		int startNode = path[0];
		int nextNode = -1;
		for (auto& e: graph) {
			if (startNode == e[0] || startNode == e[1]) {
				if (startNode == e[0])
					nextNode = e[1];
				else
					nextNode = e[0];
				bool exists = std::find(std::begin(path), std::end(path), nextNode) != std::end(path);
				if(!exists) {
					std::vector<int> newTestPath;
					newTestPath.push_back(nextNode);
					for (auto vertex: path) {
						newTestPath.push_back(vertex);
					}
					findNewCycles(graph, newTestPath, cycles);
				} else {
					if (path.size() > 2 && nextNode == path[path.size() - 1]){
						std::list<int> norm;
						norm.assign(path.begin(), path.end());
						norm.sort();
						norm.push_back(v);
						cycles.insert(norm);
					}
				}
			}
		}
	};
	
	for (int i = 0; i < 7; i++) {
		 for (int j = 0; j < 2; j++) {
	    vector<int> pt;
	 	 	pt.push_back(graph[i][j]);
	 	 	findNewCycles(graph, pt, cycles);
	  }
	}

	list<list<int>> reversedCycles;
	
	for (auto cycle: cycles)
		cycle.push_back(v);
	
	for (auto cycle: cycles) {
		list<int> rev;
		for (auto it = cycle.rbegin(); it != cycle.rend(); ++it) {
			rev.push_back(*it);
		} 
		reversedCycles.push_back(rev);
	}

	for (auto cycle: reversedCycles)
		cycles.insert(cycle);

	for (auto a: cycles) {
	  for (auto b: a) {
	 		cout << b << " ";
	  }
	  cout << endl;
	}
}



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
   using CC = std::list<std::shared_ptr<Vertex>>;
   findCycles(g,0,[](auto from,auto to) {
                     while (from != to) {
                        std::cout << (*from)->_id << " ";
                        from++;
                     }
                     std::cout << std::endl;
                  });
   std::cout << std::endl;
   return 0;
}
