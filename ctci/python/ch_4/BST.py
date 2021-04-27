'''
A binary search tree is a binary tree that has the following property: all left descendants <= root < all right descendants
'''

class Node:
  def __init__(self, value):
    self.value = value
    self.left_child = None
    self.right_child = None

  def insert(self, value):
    if self.value == value:
      return False
    elif self.value > value:
      if self.left_child:
        return self.left_child.insert(value)
      else:
        self.left_child = Node(value)
        return True
    else:
      if self.right_child:
        return self.right_child.insert(value)
      else:
        self.right_child = Node(value)
        return True

  def find(self, value):
    if self.value == value:
      return True
    elif self.value > value:
      if self.left_child:
        return self.left_child.find(value)    
      else:
        return False
    else:
      if self.right_child:
        return self.right_child.find(value)
      else:
        return False

  # root node is visited inbetween children
  def inorder(self):
    if self:
      if self.left_child:
        return self.left_child.inorder()
      print(self.value)
      if self.right_child:
        return self.right_child.inorder()

  # root node is visited before (pre) children
  def preorder(self):
    if self:
      print(self.value)
      if self.left_child:
        self.left_child.preorder()
      if self.right_child:
        self.right_child.preorder()
  
  # root node is visited after (post) children
  def postorder(self):
    if self:      
      if self.left_child:
        self.left_child.postorder()
      if self.right_child:
        self.right_child.postorder()
      print(self.value)

class BST:
  def __init__(self):
    self.root = None

  def insert(self, value):
    if self.root:
      return self.root.insert(value)
    else:
      self.root = Node(value)
      return True

  def find(self, value):
    if self.root:
      return self.root.find(value)
    else:
      return False

  def inorder(self):
    return self.root.inorder()

  def preorder(self):
    return self.root.preorder()

  def postorder(self):
    return self.root.postorder()

bst = BST()
bst.insert(15)
bst.insert(10)
bst.insert(4)
bst.insert(12)
bst.insert(22)
bst.insert(18)
bst.insert(24)
bst.postorder()