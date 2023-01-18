#perfect binary tree : every internal node has exactly two child nodes and all the leaf nodes are at the same level.


class newNode:

  def __init__(self, k):
    self.key = k
    self.right = self.left = None


# Calculate the depth
def calculateDepth(node):
  d = 0
  while (node is not None):
    d += 1
    node = node.left
  return d


# Check if the tree is perfect binary tree
def is_perfect(root, d, level=0):
  # Check if the tree is empty
  if root is None:
    return True

  # Check the presence of trees
  if (root.left is None and root.right is None):
    return (d == level + 1)
  if (root.left is None or root.right is None):
    return False

  return (is_perfect(root.left, d, level + 1)
          and is_perfect(root.right, d, level + 1))
