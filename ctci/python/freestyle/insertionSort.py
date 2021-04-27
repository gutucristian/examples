def insertionSort(lst):
  for i in range(1, len(lst)):
    j = i - 1
    value = lst[i]
    while j >= 0 and value < lst[j]:
      lst[j], lst[j+1] = value, lst[j]
      value = lst[j]
      j -= 1      
  return lst

alist = [12, -3, 10, 4, 99, 234, -123, 43, 2234, 12]
print(insertionSort(alist))