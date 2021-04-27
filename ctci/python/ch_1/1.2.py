from collections import Counter
from functools import reduce

# time complexity is O(2n) = O(n) due to traversing a and b
# space complexity is O(2n) = O(n) for storing character frequencies of a and b in dictionaries
def is_permutation_1(a, b):
  return Counter(a) == Counter(b)

# time complexity is O(n) due to traversal of s1 and s2
# space complexity is O(1) since out content buffer always has length of 128
def is_permutation(s1, s2):
  if (len(s1) != len(s2)):
    return False
     
  content = [0] * 128
  for char in s1:
    content[ord(char)] += 1
  for char in s2:
    content[ord(char)] -= 1
  return reduce(lambda x, y: x + y, content) == 0

# time complexity O(nlogn) due to sorting using Timsort
# space complexity is O(n) because sortes() returns a new sorted list (it does not sort in place)
def is_permutation_3(a, b):
  return sorted(a) == sorted(b)
