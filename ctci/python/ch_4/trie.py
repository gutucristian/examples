# https://www.youtube.com/watch?v=ZRB7rIWO81U
# https://www.youtube.com/watch?v=7XmS8McW_1U

class TrieNode:
  def __init__(self):    
    self.children = {}
    self.is_end_of_word = False

class Trie:
  def __init__(self):
    self.root = TrieNode()

  def insert(self, word):
    current = self.root
    for char in word:
      if char not in current.children:        
        current.children[char] = TrieNode()
      current = current.children[char]
    current.is_end_of_word = True
    return self

  def search(self, word):
    current = self.root
    for char in word:
      if char not in current.children:
        return False      
      current = current.children[char]
    return True

  def get_words_bellow_node(self, node, prefix=''):
    words = []
    def helper(node, string):
      for char, child in node.children.items():
        helper(child, string + [char])
      if node.is_end_of_word:
        words.append(''.join(string))
    helper(node, [prefix])
    return words

  def get_node(self, prefix):
    current = self.root
    for char in prefix:
      if char not in current.children:
        return None
      current = current.children[char]
    return current

  def get_words_by_prefix(self, prefix):
    node = self.get_node(prefix)    
    if node:
      return self.get_words_bellow_node(node, prefix)
    else:
      return None

  def __str__(self):
    return ','.join(self.get_words_bellow_node(self.root))

trie = Trie()
trie.insert('ball').insert('beer').insert('balloon').insert('bat').insert('doll').insert('dork').insert('dorm').insert('send').insert('sense')
print(trie)
print('prefix "b":', trie.get_words_by_prefix('b'))
print('prefix "ba":', trie.get_words_by_prefix('ba'))
print('prefix "bal":', trie.get_words_by_prefix('bal'))
print('prefix "dol":', trie.get_words_by_prefix('dol'))