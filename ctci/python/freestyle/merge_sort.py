import random

def partition(lst, start, end, pivot_index):
  lst[start], lst[pivot_index] = lst[pivot_index], lst[start]
  pivot = lst[start]
  i = start + 1
  j = start + 1

  while j <= end:
    if lst[j] <= pivot:
      lst[j], lst[i] = lst[i], lst[j]
      i += 1
    j += 1

  lst[start], lst[i - 1] = lst[i - 1], lst[start]
  return i - 1

def quicksort(lst, start, end): 
  if lst == None or lst == [] or start >= end: return    

  random_index = random.randint(start, end)
  pivot_index = partition(lst, start, end, random_index)
  quicksort(lst, start, pivot_index - 1)
  quicksort(lst, pivot_index + 1, end)

  return lst

lst = [8, 7, 6, 5, 4, 3, 3, 1]
print(quicksort(lst, 0, len(lst) - 1))