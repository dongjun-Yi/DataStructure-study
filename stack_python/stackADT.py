class Stack:
  # create stack
  def __init__(self):
    self.stack = []

  # create empty stack
  def check_empty(self):
    return len(self.stack) == 0

  # Adding items into stack
  def push(self, item):
    self.stack.append(item)
    print("pushed item : " + item)

  # Removing an element from the stack
  def pop(self):
    if (self.check_empty()):
      return "stack is empty"
    return self.stack.pop()
