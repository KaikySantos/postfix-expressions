#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 200

typedef struct {
  int top;
  float data[MAXTAM];
} Stack;

void startStack(Stack *stack) {
  stack->top = -1;
}

int stackIsEmpty(Stack *stack) {
  if (stack->top == -1) {
    return 1;
  } else {
    return 0;
  }
}

int stackIsFull(Stack *stack) {
  if (stack->top == MAXTAM - 1) {
    return 1;
  } else {
    return 0;
  }
}

void push(Stack *stack, float newValue) {
  if (stackIsFull(stack) == 1) {
    printf("ERROR: Stack is full! \n");
  } else {
    stack->top++;
    stack->data[stack->top] = newValue;
  }
}

float pop(Stack *stack) {
  float aux;

  if (stackIsEmpty(stack) == 1) {
    printf("ERROR: Stack is empty! \n");
  } else {
    aux = stack->data[stack->top];
    stack->top--;
    return aux;
  }
}

int valueIsOperator(char value[]) {
  return (!strcmp(value, "+") || !strcmp(value, "-") || !strcmp(value, "*") || !strcmp(value, "/"));
}

float operation(float n1, float n2, char operator[]) {
  if (!strcmp(operator, "+")) {
    return n2 + n1;
  } else if (!strcmp(operator, "-")) {
    return n2 - n1;
  } else if (!strcmp(operator, "*")) {
    return n2 * n1;
  } else if (!strcmp(operator, "/")) {
    return n2 / n1;
  }
}

float solveExpression(Stack *stack, char exp[]) {
  char *value = strtok(exp, " ");

  while (value) {
      if (valueIsOperator(value)) {
        float n1 = pop(stack);
        float n2 = pop(stack);
        float result = operation(n1, n2, value);

        push(stack, result);
      } else {
        push(stack, atof(value));
      }

      value = strtok(NULL, " ");
  }

  return stack->data[0];
}

int main(int argc, char const *argv[]) {
  char expression[] = {"5 3 2 + * 4 / 6 -"};

  printf("Resolvendo: %s \n", expression);

  Stack *stack = (Stack*)malloc(sizeof(Stack));
  startStack(stack);

  printf("Resultado: %f \n", solveExpression(stack, expression));

  return 0;
}
