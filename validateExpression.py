def validateExpression(expression):
  operators = ["+", "-", "*", "/"]
  expressionSplited = expression.split()

  # Validation length of expression
  if (len(expressionSplited) < 3):
    print("Inválido: No mínimo 3 caracteres")
    return False

  # Validation values of expression
  valuesAreValid = True
  for value in expressionSplited:
    if (not(value.isnumeric()) and not(value in operators)):
      valuesAreValid = False
  if (not(valuesAreValid)):
    print("Inválido: Valor(es) incorretos")
    return False

  # Validation first two numbers of expression
  if (not(expressionSplited[0].isnumeric() and expressionSplited[1].isnumeric())):
    print("Inválido: Dois primeiros dígitos precisam ser números")
    return False

  # Validation last value of expression is operator
  if (not(expressionSplited[-1] in operators)):
    print ("Inválido: O útimo valor da expressão deve ser um operador")
    return False

  # Validation: For every n values there are n-1 operator(s)
  totalOfValues = len([value for value in expressionSplited if value.isnumeric()])
  totalOfOperators = len([value for value in expressionSplited if not value.isnumeric()])
  if (totalOfValues != totalOfOperators + 1):
    print("Inválido: Para todos N números, devem existir N-1 operadores")
    return False

  return True