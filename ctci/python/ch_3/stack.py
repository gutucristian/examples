class StackNode:
  def __init__(self, value=None, next=None):
    self.value = value
    self.next = next

"""A stack is a linear data structure that uses last in first out ordering (LIFO). Unlike arrays,
stacks do not offer constant-time access to the ith item. However, it does allow constant-time adds
and removes, as it does not require shifting elements around. The following is a stack implementation
using linked lists.
"""
class Stack:
  def __init__(self):
    self.top = None
    self.size = 0    

  # remove from front
  def pop(self):
    if self.is_empty():
      return None
    value = self.top.value
    self.top = self.top.next
    self.size -= 1
    return value

  # add to front
  def push(self, value=None, custom_node=None):
    """Creates item and adds it to the top of the linked list.
    
    Keyword arguments:
    value -- value of the item to be added
    node -- custom item to be added
    """
    if custom_node:
      self.top = custom_node
    else:
      t = StackNode(value, self.top)    
      self.top = t
    self.size += 1
    return self # return reference object reference to enable chaining
  
  def peek(self, return_obj=False):
    """Returns value of the top item from the stack.
    
    Keyword arguments:    
    return_obj -- if True, returns object of top item from stack
    """
    if return_obj:
      return self.top    
    return self.top.value if self.top else None

  def is_empty(self):
    return self.top is None

  def __iter__(self):
    current = self.top
    while current:
      yield current
      current = current.next

  def __str__(self):
    values = [str(node.value) for node in self]
    return ' -> '.join(values)

  def __len__(self):
    return self.size

# stack = Stack()
# stack.push('a').push('b').push('c')
# print(stack)
# stack.pop()
# stack.pop()
# print(stack)