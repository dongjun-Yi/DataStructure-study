import stackADT as s


def check_parentheses(check):
  stack = s.Stack()
  n = len(check)
  pop_out = ""
  for i in range(n):
    if (check[i] == '(' or check[i] == '[' or check[i] == '{'):
      stack.push(check[i])
    if (check[i] == ')' or check[i] == ']' or check[i] == '}'):
      pop_out = stack.pop()
      if ((pop_out == '(' and check[i] != ')')
          or (pop_out == '[' and check[i] != ']')
          or (pop_out == '{' and check[i] != '}')):
        return 0
  return 1
