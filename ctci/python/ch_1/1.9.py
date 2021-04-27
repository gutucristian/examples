def is_substring(s1, s2):
  return True if s2 in s1 else False

def is_rotation(s1, s2):
  if len(s1) != len(s2):
    return False
  else:
    s1 += s1
    return is_substring(s1, s2)

s1 = 'alpine'
s2 = 'pineal'
print(is_rotation(s1, s2))