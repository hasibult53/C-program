#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; 
}

int evaluatePostfix(char* exp) {
    Stack* stack = createStack(100);
    int i, val;
    for (i = 0; exp[i]; ++i) {
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        else {
            int operand2 = pop(stack);
            int operand1 = pop(stack);
            switch (exp[i]) {
                case '+': push(stack, operand1 + operand2); break;
                case '-': push(stack, operand1 - operand2); break;
                case '*': push(stack, operand1 * operand2); break;
                case '/': push(stack, operand1 / operand2); break;
            }
        }
    }

    return pop(stack);
}

int main() {
    char exp[100];
    printf("Enter the postfix expression: ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
