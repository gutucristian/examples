from linked_list import LinkedList

class Animal:
  def __init__(self, name): 
    self.name = name   
    self.order = 0  

  def is_older_than(self, animal):
    return self.order < animal.order

class Dog(Animal):
  def __init__(self, name): 
    super().__init__(name)

class Cat(Animal):
  def __init__(self, name): 
    super().__init__(name)

class AnimalQueue:
  def __init__(self):
    self.cats = LinkedList()
    self.dogs = LinkedList()
    self.order = 0

  def enqueue(self, animal):
    if isinstance(animal, Cat):      
      self.cats.add(animal)      
    elif isinstance(animal, Dog):
      self.dogs.add(animal)
    animal.order = self.order
    self.order += 1
    return self

  def dequeue_any(self):
    if self.cats and self.dogs:
      if self.cats.head.value.is_older_than(self.dogs.head.value):
        v = self.cats.remove()
      else:
        v = self.dogs.remove()
      return v
    elif self.cats:
      return self.cats.remove()
    elif self.dogs:
      return self.dogs.remove()
    return None

  def dequeue_dog(self):
    return self.dogs.remove()

  def dequeue_cat(self):
    return self.cats.remove()

  def __str__(self):
    dogs = [node.value.name for node in self.dogs]
    cats = [node.value.name for node in self.cats]
    return 'Dogs: ' + ' -> '.join(dogs) + ' | Cats: ' + ' -> '.join(cats)

queue = AnimalQueue()
queue.enqueue(Dog('tom')).enqueue(Cat('nait')).enqueue(Dog('bob')).enqueue(Cat('sly'))
print(queue)
print(queue.dequeue_any().order) 
print(queue)

# ------------ Bellow: initial attempt ------------

# class Node:
#   def __init__(self, value, next=None):
#     self.value = value
#     self.next = next

# class AnimalQueue:
#   def __init__(self):
#     self.head = self.tail = None

#   def enqueue(self, value):
#     if self.tail is None:
#       self.tail = Node(value)
#       self.head = self.tail
#     else:
#       self.tail.next = Node(value)
#       self.tail = self.tail.next
#     return self

#   def dequeue_any(self):    
#     v = self.head.value
#     self.head = self.head.next
#     return v

#   def dequeue(self, animal_type):
#     current = self.head
#     while current and current.value != animal_type:
#       current = current.next
#     if current and current.next:      
#       current.value = current.next.value
#       current.next = current.next.next
#     elif current:
#       current = None
#     return self

#   def __iter__(self):
#     current = self.head
#     while current:
#       yield current
#       current = current.next

#   def __str__(self):
#     values = [node.value for node in self]
#     return ' -> '.join(values)