class MinHeap():
  def __init__(self):
    self.root = None
    self.nodes = [] # nodes stored as (item, priority) tuple format
    self.order_mapping = {}
  
  def bubble_up(self, i):    
    size = len(self.nodes)
    if size <= 1 or i <= 0:
      return
    node_priority = self.nodes[i][1]
    parent_node_index = (i-1) // 2
    parent_priority = self.nodes[parent_node_index][1]
    if (node_priority < parent_priority):
      self.order_mapping[self.nodes[i][0]] = parent_node_index
      self.order_mapping[self.nodes[parent_node_index][0]] = i

      self.nodes[i], self.nodes[parent_node_index] = self.nodes[parent_node_index], self.nodes[i]
      self.bubble_up(parent_node_index)

  def bubble_down(self, i):
    size = len(self.nodes)
    if size <= 1 or i > size - 1:
      return
    left_child_index = (i * 2) + 1
    right_child_index = (i * 2) + 2
    if left_child_index > size - 1 or right_child_index > size - 1:
      return
    left = self.nodes[left_child_index][1]
    right = self.nodes[right_child_index][1]
    node = self.nodes[i][1]
    (min_node, min_node_index) = (left, left_child_index) if left < right else (right, right_child_index)
    if node > min_node:
      self.order_mapping[self.nodes[i][0]] = min_node_index
      self.order_mapping[self.nodes[min_node_index][0]] = i

      self.nodes[i], self.nodes[min_node_index] = self.nodes[min_node_index], self.nodes[i]
      self.bubble_down(min_node_index)

  def push(self, node, priority):
    self.nodes.append((node, priority))
    self.order_mapping[node] = len(self.nodes) - 1

    if len(self.nodes) > 1:
      self.bubble_up(len(self.nodes) - 1)

  def pop(self):
    size = len(self.nodes)
    if size == 0:
      return None    
    elif size > 1:
      min = self.nodes[0]
      del self.order_mapping[self.nodes[0][0]]
      self.nodes[0] = self.nodes[-1]
      self.nodes.pop()
      self.bubble_down(0)
      return min
    else:
      return self.nodes.pop()

  def update_priority(self, node, priority):
    i = self.order_mapping[node] # get node index in "nodes" list
    self.nodes[i] = (node, priority) # update node's priority
    parent = (i-1) // 2
    parent, parent_priority = self.nodes[parent]
    if priority > parent_priority:
      self.bubble_down(i)
    else:
      self.bubble_up(i)

  def is_empty(self):
    return len(self.nodes) == 0

  def __str__(self):
    values = ["({},{})".format(node.name, priority) for node, priority in self.nodes]
    return ",".join(values)