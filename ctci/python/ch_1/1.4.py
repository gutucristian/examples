from collections import Counter

# Count char frequencies and return True if no more than one char freq is odd and False otherwise.
# A permutation may not have more than one type of char with odd freq.
def is_palindrome_permutation_1(a):
  counter = Counter(a)
  is_permutation = True
  for count in counter.most_common():
    if is_permutation == False:
      return is_permutation
    if count[1] % 2 == 1:
      is_permutation = False
  return True

def is_palindrome_permutation_2(a):
  # use a bit vector to signal occurence of a char
  bit_vector = [0] * 26
  for char in a:
    # get char position in bit vector using its ASCII encoding
    index = ord(char) - ord('a')
    # replace 1 with 0 to indicate that freq of this char (so far) is even
    if bit_vector[index] == 1:
      bit_vector[index] = 0
    else:      
      bit_vector[index] = 1
  # sum of bit_vector should be 1 if all but one char has a odd freq
  bit_vector_sum = sum(bit_vector)
  return bit_vector_sum == 1 or bit_vector_sum == 0

a = 'abas'
print(is_palindrome_permutation_2(a))