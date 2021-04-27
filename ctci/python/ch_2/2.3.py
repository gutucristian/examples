class Node():
  def __init__(self, data, next = None):
    self.data = data
    self.next = next

class LinkedList():
  def __init__(self):
    self.head = None

  def add(self, data):
    new_head = Node(data, self.head)
    self.head = new_head 
    return new_head   

  # deletes a node in the linked list with only a reference to itself
  # node to be deleted must not be the first or last
  def delete_middle_node(self, node):  
    if node is None or node.next is None:
      return False
    else:      
      node.data = node.next.data
      node.next = node.next.next
      return True

  def __iter__(self):
    current = self.head
    while current:
        yield current
        current = current.next

  def __str__(self):    
    values = [x.data for x in self]
    return ' -> '.join(values)


lst = LinkedList()
node = lst.add('a')
lst.add('s')
node = lst.add('b')
lst.add('c')
lst.add('C')
print(lst)
lst.delete_middle_node(node)
print(lst)