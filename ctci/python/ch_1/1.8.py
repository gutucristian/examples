def set_zero(matrix):
  row_has_zero = False
  col_has_zero = False

  amt_of_rows = len(matrix)
  amt_of_cols = len(matrix[0])

	# check if first row has a zero
  for col in range(amt_of_cols):
    if matrix[0][col] == 0:
      row_has_zero = True
      break

	# check if first column has a zero
  for row in range(amt_of_rows):
    if matrix[row][0] == 0:
      col_has_zero = True
      break

	# check for zeros in the rest of the array
  for row in range(amt_of_rows):
    for col in range(amt_of_cols):
      if matrix[row][col] == 0:
        matrix[0][col] = 0
        matrix[row][0] = 0
  
	# zero out columns
  for col in range(1, amt_of_cols):
    if matrix[0][col] == 0:
      nullify_col(matrix, col)

	# zero out rows
  for row in range(1, amt_of_rows):
    if matrix[row][0] == 0:
      nullify_row(matrix, row)

	# zero our first row
  if row_has_zero: nullify_row(matrix, 0)

	# zero out first column
  if col_has_zero: nullify_col(matrix, 0)

  return matrix

def nullify_col(matrix, col):
  for row in range(len(matrix)):
    matrix[row][col] = 0

def nullify_row(matrix, row):
  for col in range(len(matrix[0])):
    matrix[row][col] = 0
  
def print_matrix(matrix):
	for row in range(len(matrix)):
		print(matrix[row])

matrix = [
  [4, 3, 5, 6, 9],
  [0, 3, 1, 3, 0],
  [3, 4, 3, 4, 1],
  [9, 3, 4, 0, 4]
]

matrix = set_zero(matrix)
print_matrix(matrix)
