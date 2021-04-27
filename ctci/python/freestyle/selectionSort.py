def selectionSort(lst):
  for i in range(len(lst)):
    indexOfMin = i
    j = i + 1
    
    while j < len(lst):    
      if lst[j] < lst[indexOfMin]:
        indexOfMin = j
      j += 1
    
    tmp = lst[i]
    lst[i] = lst[indexOfMin]
    lst[indexOfMin] = tmp

  return lst

print(selectionSort([2, 123, 43, 12, 43234, 12]))  