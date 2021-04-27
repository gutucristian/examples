class Node():
  def __init__(self, data, next):
    self.data = data
    self.next = next

class LinkedList():
  def __init__(self):
    self.head = None

  def add(self, data):
    new_head = Node(data, self.head)
    self.head = new_head

  # iterative solution
  # O(n) time, O(1) space
  def kth_to_last(self, k):
    runner = self.head
    cur = self.head
    while k > 0:
      runner = runner.next
      k -= 1
    while runner != None:
      cur = cur.next
      runner = runner.next
    return cur.data

lst = LinkedList()
lst.add(5)
lst.add(6)
lst.add(2)
lst.add(8)
print(lst.kth_to_last(5))