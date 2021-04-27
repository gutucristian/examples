from random import randint

class Node():
  def __init__(self, value, next = None, previous = None):
    self.value = value
    self.next = next
    self.previous = previous

class LinkedList:
  def __init__(self, values = None):
    self.head = None
    self.tail = None
    if values is not None:
      self.add_multiple(values)

  def __iter__(self):
    current = self.head
    while current:
      yield current
      current = current.next

  def __str__(self):
    values = [str(node.value) for node in self]
    return ' -> '.join(values)

  def __len__(self):
    length = 0
    current = self.head 
    while current:
      length += 1
      current = current.next
    return length
  
  def add(self, value):
    """Creates Node with value and adds it to the end of the linked list.
    
    Keyword arguments:
    value -- value of the node to be added
    """
    if self.head is None:
      self.tail = self.head = Node(value)
    else:
      self.tail.next = Node(value)
      self.tail = self.tail.next
    return self.tail    

  def add_to_beginning(self, value):
    if self.head is None:
      self.tail = self.head = Node(value)
    else:
      new_head = Node(value, self.head)      
      self.head = new_head
    return self.head

  def add_multiple(self, values):
    for value in values:
      self.add(value)

  # remove Node from beginning
  def remove(self):
    v = self.head.value
    if self.head is not None:          
      self.head = self.head.next
    return v

  def generate(self, n, min_value, max_value):
    """Generates a new linked list with n nodes where each node value is in range [min_value, max_value]."""
    self.tail = self.head = None
    for _ in range(n):
      self.add(randint(min_value, max_value))
    return self