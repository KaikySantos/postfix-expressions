#include <stdio.h>
#include <stdlib.h>

#define MAXTAM 200

typedef struct {
  int top;
  float data[MAXTAM];
} Stack;

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

void push(Stack *stack, int newValue) {
  if (stackIsFull(stack) == 1) {
    printf("ERROR: Stack is full!");
  } else {
    stack->top++;
    stack->data[stack->top] = newValue;
  }
}

float pop(Stack *stack) {
  int aux;

  if (stackIsEmpty(stack) == 1) {
    printf("ERROR: Stack is empty!");
  } else {
    aux = stack->data[stack->top];
    stack->top--;
    return aux;
  }
}

int main(int argc, char const *argv[]) {
  char expression[] = {"5 3 2 + * 4 / 6 -"};

  Stack stack;
  stack.top = -1;

  return 0;
}
