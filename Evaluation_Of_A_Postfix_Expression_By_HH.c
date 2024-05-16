#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for Stack
typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

// Function to create a stack
Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$'; // '$' denotes an empty value
}

// Function to evaluate a postfix expression
int evaluatePostfix(char* exp) {
    Stack* stack = createStack(100);
    int i, val;

    // Traverse the postfix expression
    for (i = 0; exp[i]; ++i) {
        // If the current character is a digit, push it onto the stack
        if (isdigit(exp[i]))
            push(stack, exp[i] - '0');
        // If the current character is an operator, pop two operands from the stack,
        // perform the operation, and push the result back onto the stack
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
    // The result is the only element left in the stack
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
