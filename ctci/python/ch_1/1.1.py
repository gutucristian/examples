def is_unique(str):
  # if only 128 ASCII encodings exist and we have more than 128 characters then a duplicate must exist
  if len(str) > 128:
    return False  
  # the length of the set of a unique string must equal the length of the original string
  return len(set(str)) == len(str)

def is_unique(str):
  s = set()
  for char in str:
    if char in s: 
      return False 
    else:       
      s.add(char)
  return True

def is_unique(str):  
  str = sorted(str)
  # check if any neighboring characters are same. If they are then string is not unique. We check neighboring characters because if the string is sorted then all charactes that are in the same place in the alphabet will be next to each other.
  for i in range(1, len(str)):
    if str[i] == str[i-1]:
      return False      
  return True