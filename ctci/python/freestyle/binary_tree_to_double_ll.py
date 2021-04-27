class ListNode:
  def __init__(self, val, next=None):
    self.val = val
    self.next = next

class Node:
  def __init__(self, val):
    self.val = val
    self.left = None
    self.right = None

def list_to_ll(lst):
  head = prev = cur = None  
  for i in range(len(lst)):
    if i == 0:
      head = prev = ListNode(lst[i])
    else:
      cur = ListNode(lst[i])
      prev.next = cur
      prev = cur
  return head

lst = [-10, -3, 0, 5, 9]

def ll_to_lst(head):
  lst = []
  cur = head
  while cur:
    lst.append(cur.val)
    cur = cur.next
  return lst

def sorted_ll_to_bst(head):
  lst = ll_to_lst(head)
  def helper(lst, start, end):
    if start > end:
      return None
    if start == end:
      return Node(lst[start])
    mid = (start + end) >> 1
    root = Node(lst[mid])
    root.left = helper(lst, start, mid-1)
    root.right = helper(lst, mid+1, end)
    return root
  return helper(lst, 0, len(lst) - 1)

def get_bst_inorder(root):
  lst = []
  def helper(root):
    if not root: 
      return
    helper(root.left)
    lst.append(root.val)
    helper(root.right)
  helper(root)
  return lst

lst = list_to_ll(lst)
root = sorted_ll_to_bst(lst)
print(get_bst_inorder(root))