class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def in_order_traversal(root, lst=[]):
  if not root: return
  in_order_traversal(root.left)
  lst.append(root.val)
  in_order_traversal(root.right)
  return lst

def pre_order_traversal(root, lst=[]):
  if not root: return
  lst.append(root.val)
  pre_order_traversal(root.left)
  pre_order_traversal(root.right)
  return lst

n1 = Node(8)
n2 = Node(6)
n3 = Node(10)
n4 = Node(2)
n5 = Node(7)
n6 = Node(9)
n7 = Node(12)

n1.left = n2
n1.right = n3
n2.left = n4
n2.right = n5
n3.left = n6
n3.right = n7

print(in_order_traversal(n1))
print(pre_order_traversal(n1))