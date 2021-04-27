# Basically, one edit can take place in the form of replacing a character or inserting a character. Both cases are taken care of bellow.
def one_away(str1, str2):
  if len(str1) == len(str2):
    return one_edit_replace(str1, str2)
  elif len(str1) + 1 == len(str2):
    return one_edit_insert(str1, str2)
  elif len(str1) - 1 == len(str2):
    return one_edit_insert(str2, str1)
  return False

# Checks for character equality until it finds more than one error (as measured by the boolean flag 'found_diff')
def one_edit_replace(str1, str2):
  found_diff = False
  for i in range(len(str1)):
    if str1[i] != str2[i]:
      if found_diff:
        return False
      found_diff = True
  return True

# Checks for char equality. If diff is found, index for long word increments by one while index for smaller word stays the same (this simulates adding the correct character for the shorter string). If future characters are not equal then, more than one edit is required so False is returned.
def one_edit_insert(str1, str2):
  index_str1, index_str2 = 0, 0
  while index_str1 < len(str1) and index_str2 < len(str2):
    if str1[index_str1] != str2[index_str2]:
      if index_str1 != index_str2:
        return False
      index_str2 += 1
    else:
      index_str1 += 1
      index_str2 += 1
  return True        

print(one_away('pale', 'pxj'))