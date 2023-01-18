class Node:

  def __init__(self, item):
    self.left = None
    self.right = None
    self.val = item


def inorder(root):
  if (root):
    inorder(root.left)
    print(str(root.val) + "->", end="")
    inorder(root.right)


def postorder(root):
   if (root):
    postorder(root.left)
    postorder(root.right)
    print(str(root.val) + "->", end="")
  

def preorder(root):
  if (root):
    print(str(root.val) + "->", end="")
    postorder(root.left)
    postorder(root.right)
