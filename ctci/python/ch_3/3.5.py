from stack import Stack

def sort(stack):
  tmp_stack = Stack()  
  while stack.is_empty() is False:
    top = stack.pop()
    while tmp_stack.is_empty() is False and top < tmp_stack.peek():
      stack.push(tmp_stack.pop())
    tmp_stack.push(top)
  
  while tmp_stack.is_empty() is False:
    stack.push(tmp_stack.pop())

  return stack

stack = Stack()
stack.push(3).push(1).push(5).push(8)
sort(stack)
print(stack.__str__())