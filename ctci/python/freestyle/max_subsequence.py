def longest_subsequence(string, lst):
  res = ''
  for word in lst: 
    # print('{} is a subsequence of {} : {}'.format(word, string, is_subsequence(word, string)))  
    if is_subsequence(word, string) and len(word) > len(res):
      res = word
  return res

# tests if s1 is a subsequence of s2
def is_subsequence(s1, s2):
  # i: current s1 index
  i, j = 0, 0
  while i < len(s1):
    # j: current s2 index
    while j < len(s2):
      if s1[i] == s2[j]:
        break
      if j == len(s2) - 1:
        return False
      j += 1
    i += 1
  return True    

print(longest_subsequence("abppplee", ["able", "ale", "apple", "bale", "kangaroo"]))