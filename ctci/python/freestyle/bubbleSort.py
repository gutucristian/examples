def bubbleSort(lst):
  isSorted = False
  while not isSorted:
    isSorted = True
    for i in range(len(lst)-1):
      if lst[i] > lst[i+1]:
        lst[i], lst[i+1] = lst[i+1], lst[i]
        isSorted = False

  return lst

print(bubbleSort([1, 2, 123, 43, 123, 43, 2, 4, 9]))