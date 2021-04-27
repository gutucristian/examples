def rotate_matrix(matrix):
	length = len(matrix)
	amt_of_layers = length // 2
	for layer in range(amt_of_layers):
		first, last = layer, length - layer - 1		
		for i in range(first, last):
			# Select the 4 coordinates to be rotated by 90 degrees. The manner in which coordinates are selected is governed by the 'layer' we are currently on and by the current index 'i' which, itself, is bound by the length/size of the current layer.
			p1 = matrix[layer][i]
			p2 = matrix[i][-layer - 1]
			p3 = matrix[-layer - 1][-i - 1]
			p4 = matrix[-i - 1][layer]			

			# swap values of 4 coordinates (p1, p2, p3, p4 = p4, p1, p2, p3)
			matrix[layer][i] = p4
			matrix[i][-layer - 1] = p1
			matrix[-layer - 1][-i - 1] = p2
			matrix[-i - 1][layer] = p3

	return matrix

def print_matrix(matrix):
	for row in range(len(matrix)):
		print(matrix[row])

matrix = [
  [3, 2, 1, 4],
  [0, 7, 6, 9],
  [5, 2, 4, 3],
	[6, 9, 2, 4]
]

print('Original:')
print_matrix(matrix)
print('Rotated:')
m = rotate_matrix(matrix)
print_matrix(matrix)

# Another way to rotate matrix:
# 1. transpose matrix (flip each elements row with column)
# 2. change rows to rotate left or columns to rotate right
# 'change rows' means 'flip row 0 with row n, row 1 with row n-1, etc'. Similar for columns.

# Above method is easier but requires O(n) extra space.