# Time complexity (worst case): O(n^2)
# Space complexity (worst case): O(1)
# How it works:
# Iterate through entire list starting at index = 0. Now, find the smallest element in the remaining
# list that is onwards from the current index and swap the found minimum with the element at the
# current index.
def selection_sort(lst):
  for i in range(len(lst) - 1):
    j = i + 1
    min_index = i

    for j in range(j, len(lst)):
      if lst[j] < lst[min_index]:
        min_index = j

    if min_index != i:
      lst[i], lst[min_index] = lst[min_index], lst[i]

  return lst

lst = [-2, -12, 34, 5, 98, 23, 123, 79, 1]
lst1 = [849, 2, -1, 89, 3, 3, 0, 2, 1, 999]
print(selection_sort(lst))
print(selection_sort(lst1))