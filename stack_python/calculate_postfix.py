import stackADT as s


def eval(check):
  stack = s.Stack()
  n = len(check)
  for i in range(n):
    if (check[i] != '+' and check[i] != '-' and check[i] != '*'
        and check[i] != '/'):
      value = int(check[i])
      stack.push(value)
    else:
      op2 = stack.pop()
      op1 = stack.pop()
      if (check[i] == '+'):
        stack.push(op1 + op2)
      elif (check[i] == '-'):
        stack.push(op1 - op2)
      elif (check[i] == '*'):
        stack.push(op1 * op2)
      if (check[i] == '/'):
        stack.push(op1 / op2)
  return stack.pop()
