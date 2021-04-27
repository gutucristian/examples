from stack import Stack
from sys import maxsize

class StackWithMin(Stack):
  def __init__(self):
    Stack.__init__(self)
    self.min_stack = Stack()

  def cur_min(self):
    if self.min_stack.is_empty():
      return maxsize
    return self.min_stack.peek()

  def pop(self):
    value = super(StackWithMin, self).pop()
    if value == self.cur_min():
      self.min_stack.pop()
    return value

  def push(self, value):
    if value <= self.cur_min():
      self.min_stack.push(value)
    return super(StackWithMin, self).push(value)

stack = StackWithMin()
stack.push(4).push(2).push(1).push(1).push(9)
print(stack)
print(stack.min_stack.peek())
stack.pop()
print(stack)
print(stack.min_stack.peek())
stack.pop()
print(stack)
print(stack.min_stack.peek())
stack.pop()
print(stack)
print(stack.min_stack.peek())