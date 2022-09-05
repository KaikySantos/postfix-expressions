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

      print("----- Desempilhando: ", value1, value2)
      print("Pilha atual: ", stack)

      print("----- Operando: ", value1, value, value2)

      stack.append(newValue)

      print("----- Empilhando: ", newValue)
      print("Pilha atual: ", stack)
    else:
      stack.append(float(value))
      print("----- Empilhando: ", float(value))
      print("Pilha atual: ", stack)

  return stack[0]