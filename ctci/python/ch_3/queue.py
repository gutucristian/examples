class QueueNode:
  def __init__(self, value=None, next=None):
    self.value = value
    self.next = next

class Queue:
  def __init__(self):
    self.first = None
    self.last = None

  # add to rear
  def add(self, value):
    t = QueueNode(value)
    if self.last is not None:      
      self.last.next = t
    self.last = t
    if self.first is None:
      self.first = self.last
    return self

  # remove from front
  def remove(self):
    if self.first is None: 
      return None
    value = self.first.value
    self.first = self.first.next
    if self.first is None:
      self.last = None
    return value   

  def peek(self):
    if self.first is None:
      return None
    return self.first.value

  def is_empty(self):
    return self.first is None

  def __iter__(self):
    current = self.first    
    while current:
      yield current
      current = current.next

  def __str__(self):
    values = [str(node.value) for node in self]
    return ' -> '.join(values)

queue = Queue()
queue.add('a').add('b').add('c')
print(queue)