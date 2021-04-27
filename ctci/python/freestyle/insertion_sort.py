# Time complexity (worst case): O(n^2)
# Space complexity (worst case): O(1)
# How it works:
# Iterate through entire list staring at index = 0 and consider every element.
# For the current element, compare that it is greater than the previous element
# and if it is not swap with the previous element. Continue this process for the current element
# until it is in the correct place (i.e., when it is greater than the element behind it). Perform
# this process for entire list.
def insertion_sort(lst):
  for i in range(len(lst)):
    cur_index = i
    previous_index = cur_index - 1

    while cur_index > 0 and lst[cur_index] < lst[previous_index]:
      lst[cur_index], lst[previous_index] = lst[previous_index], lst[cur_index]
      cur_index -= 1
      previous_index -= 1
  
  return lst

lst = [-2, -12, 34, 5, 98, 23, 123, 79, 1]
lst1 = [849, 2, -1, 89, 3, 3, 0, 2, 1, 999]
print(insertion_sort(lst))
print(insertion_sort(lst1))