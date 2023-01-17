class Node:

  def __init__(self, data):
    self.data = data
    self.next = None


class LinkedList:

  def __init__(self):
    self.head = None

  #Insert at beignning
  def insertAtBeginning(self, data):
    new_node = Node(data)
    new_node.next = self.head
    self.head = new_node

  # Insert after a node
  def insertAfter(self, prev, data):

    if (prev is None):
      print("he given previous node must inLinkedList")
      return
    new_node = Node(data)
    new_node.next = prev.next
    prev.next = new_node

  def insertAtEnd(self, data):
    new_node = Node(data)
    if (self.head is None):
      self.head = new_node
      return

    last = self.head
    while (last.next):
      last = last.next

    last.next = new_node

  # Deleting a node
  def deleteNode(self, position):
    if self.head is None:
      return
    temp = self.head

    if position == 0:
      self.head = temp.next
      temp = None
      return
    # Find the key to be deleted
    for i in range(position - 1):
      temp = temp.next
      if temp is None:
        break

    # If the key is not present
    if temp is None:
      return
    if temp.next is None:
      return

    next = temp.next.next
    temp.next = None
    temp.next = next

  # Search an element
  def search(self, key):
    current = self.head

    while current is not None:
      if current.data == key:
        return True
      current = current.next

    return False

  # Sort the linked list
  def sortLinkedList(self, head):
    current = head
    index = Node(None)

    if head is None:
      return
    else:
      while current is not None:
        index = current.next

        while index is not None:
          if current.data > index.data:
            current.data, index.data = index.data, current.data
          index = index.next
        current = current.next

  # Print the linked list
  def printList(self):
    temp = self.head
    while (temp):
      print(str(temp.data) + " ", end="")
      temp = temp.next
