def zero_matrix(m):
	row_has_zero = False
	col_has_zero = False

	# check if first row has a zero
	for num in m[0]:
		if num == 0:
			row_has_zero = True
			break

	# check if first column has a zero
	for i in range(len(m)):
		if m[i][0] == 0:
			col_has_zero = True
			break

	# check for zeros in the rest of the array
	for i in range(1, len(m)):
		for j in range(1, len(m)):
			if m[i][j] == 0:
				m[i][0] = 0
				m[0][j] = 0

	# zero out rows
	for i in range(1, len(m)):
		if m[i][0] == 0:
			zero_out_row(m, i)

	# zero out columns
	for i in range(1, len(m[0])):
		if m[0][i] == 0:
			zero_out_column(m, i)

	# zero out first row
	if row_has_zero: zero_out_row(m, 0)

	# zero out first col
	if col_has_zero: zero_out_column(m, 0)

def zero_out_row(m, row):
	for i in range(len(m[0])):
		m[row][i] = 0

def zero_out_column(m, col):
	for i in range(len(m)):
		m[i][col] = 0

m = [[4, 0, 3, 2, 4], [0, 1, 9, 6, 5], [2, 7, 4, 1, 9], [5, 9, 2, 3, 2]]
zero_matrix(m)
print(m)
