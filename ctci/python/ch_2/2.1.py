class Node:
  def __init__(self, data, next):
    self.data = data
    self.next = next

class LinkedList():
  set = set()

  def __init__(self):
    self.head = None

  def add(self, item):
    tmp = Node(item, self.head)    
    self.head = tmp  

  def print(self):
    cur = self.head
    while cur != None:
      print('{} '.format(cur.data), end='')
      cur = cur.next    

   # O(n) space, O(1) time
  def remove_dups(self):
    cur = self.head
    prev = None
    while cur != None:
      if cur.data in self.set:
        prev.next = cur.next        
      else:
        self.set.add(cur.data)
        prev = cur
      cur = cur.next

    self.existing_nodes = set()
    return self.head

  # O(1) space, O(n^2) time
  def remove_dups_1(self):
    current = self.head
    runner = None
    previous = None
    while current != None:
      runner = current.next
      previous = current
      while runner != None:
        if runner.data == current.data:
          previous.next = runner.next
        else:
          previous = runner
        runner = runner.next
      current = current.next

    return self.head

  # reverse linked list
  def reverse(self):
    current = self.head
    previous = None

    while current:
      next = current.next
      current.next = previous
      previous = current
      current = next

    self.head = previous
      
lst = LinkedList()

lst.add(8)
lst.add(36)
lst.add(234)
lst.add(36)
lst.add(8)
lst.add(7)
lst.add(36)
lst.add(8)
lst.add(5)
lst.add(9)
lst.add(5)

# print original linked list
lst.print()
lst.remove_dups()
print()
# print linked list after removing duplicates
lst.print()
# print reversed linked list
lst.reverse()
print()
lst.print()
