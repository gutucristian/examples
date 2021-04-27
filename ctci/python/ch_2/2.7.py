class Node:
  def __init__(self, value=None, next=None):
    self.value = value
    self.next = next

def intersection(ll_a, ll_b):
  ll_a_tail, ll_a_size = get_tail_and_size(ll_a)
  ll_b_tail, ll_b_size = get_tail_and_size(ll_b)

  # the tails of intersecting linked lists should be the same
  if ll_a_tail is not ll_b_tail: return False

  longer = ll_a if ll_a_size > ll_b_size else ll_b
  shorter = ll_b if ll_a_size > ll_b_size else ll_a

  longer = get_nth_node(longer, abs(ll_a_size - ll_b_size))

  while longer and shorter:
    if longer is shorter:
      return longer.value
    longer, shorter = longer.next, shorter.next
  return False

def get_nth_node(head, n):
  cur = head
  for _ in range(n):
    cur = cur.next
  return cur

def get_tail_and_size(head):
  size = 0
  cur = head
  while cur.next:
    size += 1
    cur = cur.next
  return (cur, size)

n1_a, n1_b, n1_c, n1_d, n1_e = Node('a'), Node('b'), Node('c'), Node('d'), Node('e')
n1_a.next, n1_b.next, n1_c.next, n1_d.next = n1_b, n1_c, n1_d, n1_e

n2_a, n2_b = Node('q'), Node('w')
n2_a.next, n2_b.next = n2_b, n1_d

print(intersection(n1_a, n2_a))