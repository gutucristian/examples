def quicksort(lst):
  if (lst == []) or (len(lst) == 1):
    return lst
  else:
    pivot = lst[0]
    lst = partition(lst)
    pivotIndex = lst.index(pivot)
    # left subarray up to pivot
    left = lst[:pivotIndex]
    # right subarray not including pivot
    right = lst[pivotIndex+1:]
    return quicksort(left) + [pivot] + quicksort(right)

def partition(lst):
  pivot = lst[0]
  leftmark = 1
  rightmark = len(lst) - 1
  done = False

  while not done:

    # place leftmark <= rightmark so that we avoid an out of bound error    
    while leftmark <= rightmark and lst[leftmark] < pivot:
      leftmark += 1
    
    # we use >= for lst[rightmark] >= pivot because we want to make sure that if we reach a value
    # equal to the pivot we keep going left so we point to a value less than the pivot so that upon
    # swap everything to the left is smaller
    while lst[rightmark] >= pivot and rightmark >= leftmark:
      rightmark -= 1

    if rightmark < leftmark:
      lst[rightmark], lst[0] = pivot, lst[rightmark]
      done = True
    else:
      lst[leftmark], lst[rightmark] = lst[rightmark], lst[leftmark]

  return lst

alist = [56, 54, 43, 23, 1, -1]
print('unsorted list:', alist)
print('sorted list:', quicksort(alist))