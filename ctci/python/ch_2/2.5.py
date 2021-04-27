from linked_list import LinkedList

def sum_lists_1(ll_a, ll_b):
	carry = 0
	node_1, node_2 = ll_a.head, ll_b.head
	ll = LinkedList()

	while node_1 or node_2:
		sum = carry
		if node_1:
			sum += node_1.value
			node_1 = node_1.next
		if node_2:
			sum += node_2.value
			node_2 = node_2.next

		carry = sum // 10  # gives how many times 10 fits into sum
		ll.add(sum % 10) # adds to the end (i.e. tail) of the linked list to maintain reversed order

	if carry: ll.add(carry)

	return ll

def sum_lists_2(node_1, node_2, carry):
	if node_1 == None and node_2 == None and carry == None:
		return None
	sum = carry
	if node_1: sum += node_1.value
	if node_2: sum += node_2.value
	result = Node(sum % 10)
	if node_1 and node_2:
		more = sum_lists_2(node_1.next, node_2.next, sum // 10)
		result.next = more
	return result

def sum_lists_followup(ll_a, ll_b):
	# pad shorter list with zeros
	if len(ll_a) > len(ll_b):
		for _ in range(len(ll_a) - len(ll_b)):
			ll_b.add_to_beginning(0)
	else:
		for _ in range(len(ll_b) - len(ll_a)):
			ll_a.add_to_beginning(0)

	result = 0
	n1, n2 = ll_a.head, ll_b.head
	while n1 and n2:
		result = (result * 10) + n1.value + n2.value
		n1, n2 = n1.next, n2.next

	ll = LinkedList()
	ll.add_multiple([int(i) for i in str(result)])

	return ll

# initial values are given in reverse because LinkedList (by default) adds values to tail
ll_a = LinkedList([1, 0, 0])
ll_b = LinkedList([9, 9])

print(sum_lists_followup(ll_a, ll_b))