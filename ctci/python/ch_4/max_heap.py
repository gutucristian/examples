'''parent: index / 2
left: index * 2
right: (index * 2) + 1

max heap operations:
1. push(value)
2. peek()
3. pop()

How to perform operations assuming heap is represented as a list
push:
- add value to end of array
- float value up to its proper position
peek:
- return first element in heap list
pop:
- swap top (max) with last element in heap list
- delete it
- bubble down the top element (index 1) to its proper position
- return max
'''

class MaxHeap:
  def __init__(self, values=[]):   
    self.heap = [0] 
    for value in values:
      self.push(value)

  def push(self, value):
    self.heap.append(value)
    self.float_up(len(self.heap) - 1)

  def peek(self):
    if self:
      return self.heap[0]
    else:
      return False

  def pop(self):
    if len(self.heap) >= 2:
      self.swap(1, len(self.heap) - 1)
      max = self.heap.pop()
      self.bubble_down(1)
    elif len(self.heap) == 1:
      max = self.heap[1]
    else:
      max = False
    return max

  def swap(self, i, j):
    self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

  def float_up(self, index):
    parent_index = index // 2
    if parent_index < 1:
      return
    elif self.heap[index] > self.heap[parent_index]:
      self.swap(index, parent_index)
      self.float_up(parent_index)
    else:
      return

  def bubble_down(self, index):
    left = index * 2
    right = (index * 2) + 1
    largest = index
    if len(self) > left and self.heap[largest] < self.heap[left]:
      largest = left
    if len(self) > right and self.heap[largest] < self.heap[right]:
      largest = right
    if largest != index:
      self.swap(index, largest)
      self.bubble_down(largest)
    return

m = MaxHeap([95, 3, 21])
print(m.heap)
m.push(10)
print(m.heap)
m.push(109)
print(m.heap)