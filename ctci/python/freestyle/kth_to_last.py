def kth_to_last(head, k):
  if head:
    index = kth_to_last(head.next, k) + 1
    if (index == k): print("kth node is {}".format(head.value))
    return index
  else:
    return 0

def kth_to_last(head, k):
  runner = head
  for _ in range(k):
    if runner:
      runner = runner.next
    else:
      return -1
  cur = head
  while runner:
    runner = runner.next
    cur = cur.next
  return cur

class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

  def __str__(self):
    return str(self.value)

class LinkedList:
  def __init__(self, head=None):
    self.head = head

  def __iter__(self):
    current = self.head
    while current:
      yield current
      current = current.next

  def add(self, value):
    if self.head:
      cur = self.head
      while cur.next:
        cur = cur.next
      cur.next = Node(value)
    else:
      self.head = Node(value)
    return self

 # def add_many(*args):
 #   if self.head:
 #     cur = self.head
 #     
 #     for arg in args:

  def __str__(self):
    values = [str(node) for node in self]
    return ' -> '.join(values)



ll = LinkedList()
ll.add(3).add(8).add(2).add(5).add(7).add(10)
print(ll)
print(kth_to_last(ll.head, 2))