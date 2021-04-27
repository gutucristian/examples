# get repeating elements in list in O(n) time and O(1) space
def get_repeating(arr, size):
  for i in range(size):
    tmp = abs(arr[i])
    if arr[tmp] >= 0:
      arr[tmp] = -arr[tmp]
    else:
      print(tmp, end = '')

arr = [1, 8, 3, 1, 3, 6, 6]
get_repeating(arr, len(arr))