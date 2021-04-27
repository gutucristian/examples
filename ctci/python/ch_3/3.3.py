class Node:
  def __init__(self, value):
    self.value = value
    self.above = None
    self.below = None

class Stack:
  def __init__(self, capacity):
    self.capacity = capacity
    self.size = 0
    self.top = None
    self.bottom = None
  
  def join(self, above, below):
    if above is not None:
      above.below = below
    if below is not None:
      below.above = above      

  def push(self, value):
    if self.size >= self.capacity:
      return False
    self.size += 1
    n = Node(value)
    if self.size == 1: self.bottom = n
    self.join(n, self.top)
    self.top = n
    return True

  def pop(self):
    if self.size == 0:
      return None
    top = self.top
    self.top = self.top.below
    self.size -= 1
    return top

  def __len__(self):
    return self.size

  def is_empty(self):
    return self.size == 0

  def is_full(self):
    return self.size == self.capacity

  def remove_bottom(self):
    b = self.bottom
    self.bottom = self.bottom.above
    if self.bottom is not None:
      self.bottom.below = None
    self.size -= 1
    return b.value

  def __iter__(self):
    current = self.top
    while current:
      yield current
      current = current.below

  def __str__(self):
    values = [str(node.value) for node in self]
    return ' -> '.join(values)

class SetOfStacks:
  def __init__(self, capacity):    
    self.stacks = []
    self.capacity = capacity

  def get_last_stack(self):
    if len(self.stacks) == 0: return None
    return self.stacks[-1]

  def push(self, value):
    last = self.get_last_stack()
    if last is None or last.is_full():
      stack = Stack(self.capacity)
      stack.push(value)
      self.stacks.append(stack)
    else:
      last.push(value)
    return self

  def pop(self):
    last = self.get_last_stack()
    if last is None: raise Exception('Empty stack exception')
    value = last.pop()
    if len(last) == 0: del self.stacks[-1]
    return value

  def is_empty(self):
    return True if self.get_last_stack() is None else False

  def left_shift(self, index, remove_top):
    stack = self.stacks[index]
    if remove_top:
      removed_item = stack.pop()
    else:
      removed_item = stack.remove_bottom()    
    if len(stack) == 0:
      del self.stacks[index]
    elif len(self.stacks) > index + 1: # if not the last stack
      value = self.left_shift(index+1, False)
      stack.push(value)
    return removed_item

  def pop_at(self, index):
    return self.left_shift(index, True)

  def __str__(self):
    values = [stack.__str__() for stack in self.stacks]
    return ' | '.join(values)


stack = SetOfStacks(3)
stack.push(2).push(1).push(9)
stack.push(5).push(7).push(6)
stack.push(1).push(0).push(3)
stack.push(9).push(2).push(4)
stack.push(7)
print(stack)
stack.pop_at(1)
print(stack)