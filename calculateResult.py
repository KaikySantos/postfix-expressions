def operation(value1, value2, operator):
  if (operator == "+"):
    return value1 + value2
  elif (operator == "-"):
    return value1 - value2
  elif (operator == "*"):
    return value1 * value2
  elif (operator == "/"):
    return value1 / value2

def calculateResult(expression):
  operators = ["+", "-", "*", "/"]
  expressionSplited = expression.split()
  stack = []

  for value in expressionSplited:
    if (value in operators):
      value1 = stack[-2]
      value2 = stack[-1]
      newValue = operation(value1, value2, value)

      stack.pop()
      stack.pop()

      stack.append(newValue)
    else:
      stack.append(float(value))

  return stack[0]