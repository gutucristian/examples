from min_heap import MinHeap

class Graph:
  def __init__(self, nodes = {}) :
    self.nodes = nodes

  # kwargs is a list of key-value pairs where key is
  # a node name and value is a pointer to the node
  def add_nodes(self, **kwargs) :
    for key in kwargs:
      self.nodes[key] = kwargs[key]

  def dijkstra(self, start):
    seen = set()
    heap = MinHeap()

    heap.push(start, start.val)
    seen.add(start)

    while not heap.is_empty():
      top, priority = heap.pop()

      for name, edge_dist in top.neighbors.items():
        tmp_distance = edge_dist + priority
        neighbor = self.nodes[name]
        if tmp_distance < neighbor.val:
          neighbor.parent = top
          neighbor.val = tmp_distance
          if neighbor in seen:
            heap.update_priority(neighbor, neighbor.val)
          else:
            heap.push(neighbor, neighbor.val)

  def print_shortest_path(self, node):
    if node:
      self.print_shortest_path(node.parent) 
      print(node.name, end='')
