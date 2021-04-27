class Node:
  def __init__(self, name, val=float('inf')):    
    self.val = val
    self.neighbors = {} # key is Node name, value is edge length to Node
    self.parent = None
    self.name = name

  # kwargs is a list of key-value args where key is node
  # reference and value is the distance to that node
  def add_neighbors(self, **kwargs):
    for key in kwargs:
      self.neighbors[key] = kwargs[key]
    return self
