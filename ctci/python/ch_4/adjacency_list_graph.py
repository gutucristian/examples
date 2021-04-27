'''
The adjacency list aproach is the most common way to represent a graph. 
It follows one simple principle: every graph vertex (i.e., root or node)
stores a list of all other vertices it is connected to (i.e., neighbors).'''

class Vertex:
  def __init__(self, value):
    self.value = value
    self.neighbors = []

  def add_neighbor(self, vertex):
    if vertex not in self.neighbors:
      self.neighbors.append(vertex)
      return self
    return None

class Graph:
  def __init__(self):
    self.vertices = {}

  def add_vertex(self, vertex):
    if vertex.value not in self.vertices:
      self.vertices[vertex.value] = vertex
      return self
    return None # error value

  def add_edge(self, v1, v2):
    if v1.value in self.vertices and v2.value in self.vertices:
      self.vertices[v1.value].add_neighbor(v2)
      self.vertices[v2.value].add_neighbor(v1)
      return self
    return None

  def __str__(self):
    graph = []
    for (name, vertex) in self.vertices.items():
      neighbors = []
      for neighbor_vertex in vertex.neighbors:
        neighbors.append(str(vertex.value) + '->' + str(neighbor_vertex.value))
      neighbors = ', '.join(neighbors)
      graph.append('vertex' + str(name) + ': ' + str(neighbors))
    return '\n'.join(graph)

graph = Graph()

v0 = Vertex(0)
v1 = Vertex(1)
v2 = Vertex(2)
v3 = Vertex(3)

graph.add_vertex(v0).add_vertex(v1).add_vertex(v2).add_vertex(v3)
graph.add_edge(v0, v1).add_edge(v1, v2).add_edge(v2, v0).add_edge(v2, v3).add_edge(v3, v2)

print(graph)