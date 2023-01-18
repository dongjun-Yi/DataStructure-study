#binary tree :  each parent node can have at most two children.
#Binary search tree is a data structure that quickly allows us to maintain a sorted list of numbers.
# Create a node
class Node:

  def __init__(self, key):
    self.key = key
    self.left = None
    self.right = None


# Inorder traversal
def inorder(root):
  if root is not None:
    # Traverse left
    inorder(root.left)

    # Traverse root
    print(str(root.key) + "->", end=' ')

    # Traverse right
    inorder(root.right)


def insert(node, key):
  if (node is None):
    return Node(key)

  if (key < node.key):
    node.left = insert(node.left, key)
  else:
    node.right = insert(node.right, key)
  return node


# Find the inorder successor
def minValueNode(node):
  current = node

  # Find the leftmost leaf
  while (current.left is not None):
    current = current.left
  return current


# Deleting a node
def deleteNode(root, key):
  # Return if the tree is empty
  if root is None:
    return root
  if key < root.key:
    root.left = deleteNode(root.left, key)
  elif key > root.key:
    root.right = deleteNode(root.right, key)
  else:
    if root.right is None:
      temp = root.left
      root = None
      return temp

    elif root.left is None:
      temp = root.right
      root = None
      return temp

    # If the node has two children,
    # place the inorder successor in position of the node to be deleted
    temp = minValueNode(root.right)
    root.key = temp.key
    root.right = deleteNode(root.right, temp.key)

  return root
