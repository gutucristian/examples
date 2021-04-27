from linked_list import LinkedList

ll = LinkedList([45, 5, 8, 13, 27, 2, 7, 25])
node = ll.add(11)

# O(n) time, O(1) space
def partition(ll, ref_node):
  # find ref_node and swap with first node
  for node in ll:
    if node.value == ref_node.value:
      ll.head.value, node.value = node.value, ll.head.value
      break
  
  runner = ll.head.next
  border = ll.head

  while runner is not None:
    if runner.value < ll.head.value:      
      border.next.value, runner.value = runner.value, border.next.value
      border = border.next    
    runner = runner.next    
  
  border.value, ll.head.value = ll.head.value, border.value

# O(n) space, O(n) time
def partition(ll, ref_node):
  res = LinkedList()

  for node in ll:    
    if node.value < ref_node.value:
      res.add_to_beginning(node.value)
    else:
      res.add(node.value)            

  return res

print('Original: {}'.format(ll))
ll = partition(ll, node)
print('Partitioned: {}'.format(ll))