from min_heap import MinHeap
from node import Node
from graph import Graph

heap = MinHeap()
graph = Graph()

A = Node("A", 0)
B = Node("B")
C = Node("C")
D = Node("D")
E = Node("E")
F = Node("F")

A.add_neighbors(B=3, C=1)
B.add_neighbors(A=3, C=1, D=5)
C.add_neighbors(A=1, B=1, D=2, E=4)
D.add_neighbors(B=5, C=2, E=1, F=6)
E.add_neighbors(C=4, D=1, F=3)
F.add_neighbors(D=6, E=3)

graph.add_nodes(A=A,B=B,C=C,D=D,E=E,F=F)
graph.dijkstra(A)

print("Shortest path to node F:", end='')
graph.print_shortest_path(F)

print("\nShortest path to E:", end='')
graph.print_shortest_path(E)

print("\nShortest path to B:", end='')
graph.print_shortest_path(B)

# A = (Node("A", 4), 4) # format: (node, priority)
# heap.push(A[0], A[1])
# print("min heap: {}".format(heap))
# heap.push(Node("B", 1), 1)
# print("min heap: {}".format(heap))
# heap.push(Node("C", 2), 2)
# print("min heap: {}".format(heap))
# heap.push(Node("D", 5), 5)
# print("min heap: {}".format(heap))
# heap.pop()
# E = (Node("E", 3), 3)
# print("min heap: {}".format(heap))
# heap.push(E[0], E[1])
# print("min heap: {}".format(heap))
# heap.update_priority(A[0], 1)
# print("min heap: {}".format(heap))
# heap.push(Node("F", 9), 9)
# print("min heap: {}".format(heap))
# heap.update_priority(A[0], 10)
# print("min heap: {}".format(heap))