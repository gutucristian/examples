import heapq

def find_kth_largest(nums, k):
  min_heap = []
  for n in nums:
    heapq.heappush(min_heap, n)
    if len(min_heap) > k:
      heapq.heappop(min_heap)

  return heapq.heappop(min_heap)

lst = [3, 4, 2, 0, -1, 39]
print(find_kth_largest(lst, 2))