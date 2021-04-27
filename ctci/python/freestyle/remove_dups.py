def remove_dups(head):
  seen = set([head.value]);
  cur = head
  while cur.next:
    if cur.next.value in seen:
      cur.next = cur.next.next
    else:
      seen.add(cur.value)
      cur = cur.next
  return head

def remove_dups_b(head):
  cur = head
  while cur:
    runner = cur
    while runner.next:
      if runner.next.value == cur.value:
        runner.next = runner.next.next
      else:
        runner = runner.next
    cur = cur.next
  return head

class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next
  
  def __str__(self):
    return str(self.value)

class LinkedList:
  def __init__(self, head=None):
    self.head = head

  def add(self, value):
    if self.head:
      cur = self.head
      while cur.next:
        cur = cur.next
      cur.next = Node(value)
    else:
      self.head = Node(value)
    return self

  def __iter__(self):
    current = self.head
    while current:
      yield current
      current = current.next

  def __str__(self):
    values = [str(node) for node in self]
    return ' -> '.join(values)

ll = LinkedList()
ll.add(3).add(5).add(3).add(4).add(5)
print(ll)
remove_dups_b(ll.head)
print(ll)
