def mergesort(lst):
  lstLength = len(lst)
  if lstLength == 1:
    return lst
  else:
    midpoint = lstLength // 2
    left = lst[:midpoint]
    right = lst[midpoint:]
    return merge(mergesort(left), mergesort(right))

def merge(left, right): 
  leftLength = len(left)
  rightLength = len(right)
  res = [] 
  i = 0
  j = 0

  while i < leftLength and j < rightLength:
    if left[i] <= right[j]:
      res.append(left[i])
      i += 1
    else:
      res.append(right[j])
      j += 1    

  while i < leftLength:
    res.append(left[i])
    i += 1
  
  while j < rightLength:        
    res.append(right[j])
    j += 1
  
  return res

print(mergesort([4,1,27,-9, 1010, -98]))
