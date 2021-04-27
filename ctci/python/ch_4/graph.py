class Vertex:
	def __init__(self, name):
		self.name = name		

class Graph:
	def __init__(self):
		self.vertices = {}
		self.edges = []
		self.edge_indices = {}

	def add_vertex(self, vertex):
		if isinstance(vertex, Vertex) and vertex.name not in self.vertices:
			self.vertices[vertex.name] = vertex
			for row in self.edges: row.append(0) # add column to account new vertex
			self.edges.append([0] * (len(self.edges)+1)) # add row to account new vertex
			self.edge_indices[vertex.name] = len(self.edge_indices)
			return self
		return None

	def add_edge(self, v1, v2, weight=1):
		if v1.name in self.vertices and v2.name in self.vertices:
			self.edges[self.edge_indices[v1.name]][self.edge_indices[v2.name]] = weight
			self.edges[self.edge_indices[v2.name]][self.edge_indices[v1.name]] = weight
			return self
		return None

	def print_graph(self):
		for (vertex, i) in self.edge_indices.items():
			print(str(vertex) + ' ', end='')
			for j in range(len(self.edges)):
				print(self.edges[i][j], end='')
			print(' ')

# class Vertex:
# 	def __init__(self, name):
# 		self.name = name
# 		self.neighbors = []

# 	def add_neighbor(self, vertex):
# 		if vertex not in self.neighbors:
# 			self.neighbors.append(vertex)
# 			return self

# class Graph:
# 	def __init__(self):
# 		self.vertices = {}

# 	def add_vertex(self, vertex):
# 		if isinstance(vertex, Vertex) and vertex.name not in self.vertices:
# 			self.vertices[vertex.name] = vertex
# 			return vertex
# 		return None
	
# 	def add_edge(self, v1, v2):
# 		if v1 in self.vertices and v2 in self.vertices:
# 			self.vertices[v1.name].add_neighbor(v2)
# 			self.vertices[v2.name].add_neighbor(v1)
# 			return True
# 		return False

# 	def __str__(self):
# 		graph = []
# 		for (name, vertex) in self.vertices.items():
# 			neighbors = ', '.join([str(vertex.name) for vertex in vertex.neighbors])
# 			graph.append(str(name) + ': ' + neighbors)
# 		return ' | '.join(graph)

graph = Graph()
v0 = Vertex(0)
v1 = Vertex(1)
v2 = Vertex(2)
v3 = Vertex(3)
graph.add_vertex(v0).add_vertex(v1).add_vertex(v2).add_vertex(v3)
graph.add_edge(v0, v1).add_edge(v1, v2)
graph.print_graph()