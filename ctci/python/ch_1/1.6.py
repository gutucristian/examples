def string_compression(string):  
  count = 1
  res = []
  i = 0
  
  while i < len(string)-1:
    if string[i] == string[i+1]:
      count += 1
    else:
      res.append(string[i] + str(count))
      count = 1  
    i += 1     
  
  if i > 0: 
    res.append(string[i] + str(count)) 
    
  return min(string, ''.join(res), key = len)

print(string_compression('aabcccccaaa'))