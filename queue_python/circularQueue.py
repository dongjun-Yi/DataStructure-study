#when we reach the end of the queue, we start from the beginning of the queue.
class MyCircularQueue:

  def __init__(self, k):
    self.k = k
    self.queue = [None] * k
    self.head = self.tail = -1

# Insert an element into the circular queue
# 1. check queue full
# 2. check if queue is first put
# 3. enqueue

  def enqueue(self, data):
    if ((self.tail + 1) % self.k == self.head):
      print("The circular queue is full\n")

    elif (self.head == -1):
      self.head = 0
      self.tail = 0
      self.queue[self.tail] = data

    else:
      self.tail = (self.tail + 1) % self.k
      self.queue[self.tail] = data


# Delete an element from the circular queue
# 1. check queue is empty
# 2. check if queue is last output
# 3. dequeue

  def dequeue(self):
    if (self.head == -1):
      print("The queue is empty")

    #only one element
    elif (self.head == self.tail):
      temp = self.queue[self.head]
      self.head = -1
      self.tail = -1
      return temp

    else:
      temp = self.queue[self.head]
      self.head = (self.head + 1) % self.k
      return temp

  def printQueue(self):
    if (self.head == -1):
      print("No element in the circular queue")
    elif (self.tail > self.head):
      for i in range(self.head, self.tail + 1):
        print(self.queue[i], end="")
      print()
    else:
      for i in range(self.head, self.k):
        print(self.queue[i], end=" ")
      for i in range(0, self.tail + 1):
        print(self.queue[i], end=" ")
      print()
