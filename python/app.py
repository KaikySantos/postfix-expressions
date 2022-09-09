from validateExpression import *
from calculateResult import *

expression = input("Digite a expressão em notação posfixa: ")

if (validateExpression(expression)):
  print("Resultado: ", calculateResult(expression))