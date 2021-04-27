from stack import Stack

class MyQueue:
  def __init__(self):
    self.stack_newest = Stack()
    self.stack_oldest = Stack()

  def add(self, value):
    self.stack_newest.push(value)
    return self

  def shift_stacks(self):
    if self.stack_oldest.is_empty():
      while self.stack_newest.is_empty() is False:
        self.stack_oldest.push(self.stack_newest.pop())

  def peek(self):
    self.shift_stacks()
    self.stack_oldest.peek()

  def remove(self):    
    self.shift_stacks()
    return self.stack_oldest.pop()

queue = MyQueue()
queue.add(1).add(2)
print(queue.remove())
queue.add(3)
print(queue.remove())
queue.add(4)
print(queue.remove())
print(queue.remove())