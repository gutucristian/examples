class Node:
  def __init__(self, value=None, next=None):
    self.value = value
    self.next = next

# Use Floyd's cycle finding algorithm. O(n) time, O(1) space
def loop_detection(head):
  slow = fast = head
  
  while fast and fast.next:
    slow = slow.next
    fast = fast.next.next
    if slow is fast:      
      break
  
  if fast is None or fast.next is None:
    return None
    
  slow = head
  while slow is not fast:
    slow = slow.next
    fast = fast.next 
  
  return fast

n1_a, n1_b, n1_c, n1_d, n1_e = Node('a'), Node('b'), Node('c'), Node('d'), Node('e')
n1_a.next, n1_b.next, n1_c.next, n1_d.next, n1_e.next = n1_b, n1_c, n1_d, n1_e, n1_b

print(loop_detection(n1_a).value)