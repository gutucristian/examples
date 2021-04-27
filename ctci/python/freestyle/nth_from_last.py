class Node:
  def __init__(self, val, next=None):
    self.val = val
    self.next = next

def remove_nth_from_end(n, head):
  fast = slow = head
  for _ in range(n):
    fast = fast.next
  if not fast:
    return head.next
  while fast.next:
    fast = fast.next
    slow = slow.next
  slow.next = slow.next.next
  return head

n1 = Node(3)
n2 = Node(2)
n3 = Node(4)
n4 = Node(5)

n1.next = n2
n2.next = n3
n3.next = n4

res = remove_nth_from_end(4, n1)
print(res.val)