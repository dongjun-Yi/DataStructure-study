# full binary tree : every parent node/internal node has either two or no children.
# Checking if a binary tree is a full binary tree in Python


class Node:

  def __init__(self, item):
    self.item = item
    self.leftChild = None
    self.rightChild = None


# Checking full binary tree


def isFullTree(root):
  # Tree empty case
  if root is None:
    return True

  # Checking whether child is present
  if (root.rightChild is None and root.leftChild is None):
    return True
  if root.leftChild is not None and root.rightChild is not None:
    return (isFullTree(root.leftChild) and isFullTree(root.rightChild))
  return False
