class Node:
	def __init__(self, value=None, next=None):
		self.value = value
		self.next = next

def is_palindrome(head):
	reversed = reverse_and_clone(head)
	return is_equal(head, reversed)

def reverse_and_clone(node):
	head = None
	while node:
		n = Node(node.value)
		n.next = head
		head = n
		node = node.next
	return head

def is_equal(n1, n2):
	while n1 or n2:
		if n1.value != n2.value:
			return False
		n1 = n1.next
		n2 = n2.next
	return n1 == None and n2 == None

# iterative approach
def is_palindrome(head):
	slow = fast = head
	first_half = []

	while fast != None and fast.next != None:
		first_half.append(slow.value)
		slow = slow.next
		fast = fast.next.next

	# if linked list length is odd, then above while loop will stop bec. fast.next is None
	if fast != None : slow = slow.next

	while slow != None:
		top = first_half.pop()
		if top != slow.value:
			return False
		slow = slow.next
	return True

n1_a, n1_b, n1_c, n1_d = Node('a'), Node('b'), Node('b'), Node('a')
n1_a.next, n1_b.next, n1_c.next = n1_b, n1_c, n1_d

print(is_palindrome(n1_a))