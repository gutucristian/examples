import unittest

# url has a buffer (i.e., empty space) at the end which guarantees that there will be enough space to insert all required '%20' edits
# true_length is the index of the last non space character

def urlify(url, true_length):  
  # convert url to list because Python strings are immutable (i.e., they cannot be modified)
  url = list(url)
  space_count = 0
  # count spaces that need to be replaced with '%20'
  for i in range(true_length):
    if url[i] == ' ': space_count += 1
  # calculate the index of the end of the string 
  index = true_length + 2 * space_count # index = len(url) would also work
  # start at the last non space character
  for i in range(true_length - 1, 0, -1):    
    if url[i] == ' ':
      url[index - 1] = '0'
      url[index - 2] = '2'
      url[index - 3] = '%'
      index -= 3
    else:
      url[index - 1] = url[i]
      index -= 1
  return ''.join(url)

class Test(unittest.TestCase):
  data = [
    (list('Mr John Smith    '), 13, 'Mr%20John%20Smith'),
    (list('a bc  '), 4, 'a%20bc'),
  ]

  def test_urlify(self):
    for (test_string, length, expected) in self.data:
      actual = urlify(test_string, length)      
      self.assertEqual(actual, expected)

if __name__ == "__main__":
  unittest.main()