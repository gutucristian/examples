# TODO: implement flexible stack size solution

class MultiStack:
  def __init__(self, num_of_stacks, stack_size):
    self.num_of_stacks = num_of_stacks
    self.stack_size = stack_size
    self.array = [None] * num_of_stacks * stack_size
    self.sizes = [0] * self.num_of_stacks # represents the current size of each stack

  def index_of_top(self, stack_num):
    offset = self.stack_size * stack_num
    return offset + self.sizes[stack_num] - 1

  def is_full(self, stack_num):
    return self.sizes[stack_num] == self.stack_size

  def is_empty(self, stack_num):
    return self.sizes[stack_num] == 0

  def push(self, stack_num, value):    
    if self.is_full(stack_num):
      raise Exception('Full stack exception')
    self.sizes[stack_num] += 1
    index_of_top = self.index_of_top(stack_num)
    self.array[index_of_top] = value    

  def pop(self, stack_num):
    if self.is_empty(stack_num):
      raise Exception('Empty stack exception')
    index_of_top = self.index_of_top(stack_num)
    value = self.array[index_of_top]
    self.array[index_of_top] = None
    self.sizes[stack_num] -= 1
    return value

stack = MultiStack(3, 3)
stack.push(0, 3)
stack.push(0, 2)
stack.push(0, 9)
print(stack.array)
stack.pop(0)
stack.pop(0)
print(stack.array)
stack.push(2, 7)
stack.push(2, 7)
stack.push(2, 7)
print(stack.array)