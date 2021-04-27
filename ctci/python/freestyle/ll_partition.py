class Node:
  def __init__(self, value=None, next=None):
    self.next = next
    self.value = value

def partition(node, x):
  head = tail = Node(x)

  while node is not None:
    if node.value >= x:
      tail.next = Node(node.value)
      tail = tail.next
    else:
      tmp = head
      head = Node(node.value)
      head.next = tmp
    node = node.next

  return head

n5 = Node(20)
n4 = Node(5, n5)
n3 = Node(9, n4)
n2 = Node(3, n3)
n1 = Node(4, n2)

node = partition(n1, 5)
res = []

while node is not None:
  if node.next != None:
    res.append(str(node.value) + ' -> ')
  else:
    res.append(str(node.value))
  node = node.next

print(''.join(res))