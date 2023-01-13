import stackADT as s
import math


def check_palindrome(check):
  stack = s.Stack()
  n = len(check)
  for i in range(n):
    stack.push(check[i])

  for i in range(math.trunc(n / 2)):
    pop_out = stack.pop()
    if (pop_out != check[i]):
      return 0

  return 1
