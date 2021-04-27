from collections import deque

class Node:
  def __init__(self, val):
    self.val = val
    self.next = None

def create_minimal_BST(lst, start, end):
  if end < start:
    return None
  middle = (start + end) // 2
  n = Node(lst[middle])
  n.left = create_minimal_BST(lst, start, middle - 1)
  n.right = create_minimal_BST(lst, middle + 1, end)
  return n

# print tree with level order traversal
def print_tree(root):
  q = deque([])
  q.append(root)
  lvl_size = 0
  count = 1
  while len(q) > 0:
    lvl_size = 0
    while count > 0:
      u = q.popleft()
      if not u: continue
      print(str(u.val) + " ", end='')
      for node in [u.left, u.right]:
        if node: 
          q.append(node)
          lvl_size += 1
      count -= 1
    print()
    count = lvl_size

lst = [2, 3, 7, 9, 10, 14]
root = create_minimal_BST(lst, 0, len(lst) - 1)
print_tree(root)