#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
    }
    return -1;
}
void push(Stack* stack, char item) {
    stack->array[++stack->top] = item;
}
char pop(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}
char peek(Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top];
    return '$';
}
char* infixToPostfix(char* exp) {
    Stack* stack = createStack(strlen(exp));
    char* postfix = (char*)malloc((strlen(exp) + 1) * sizeof(char));
    int i, k;
    for (i = 0, k = -1; exp[i]; ++i) {
        if (isalnum(exp[i]))
            postfix[++k] = exp[i];
        else if (exp[i] == '(')
            push(stack, exp[i]);
        else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return NULL;
            else
                pop(stack);
        }
        else {
            while (!isEmpty(stack) && precedence(exp[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, exp[i]);
        }
    }
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
    return postfix;
}

int main() {
    char exp[100];
    printf("Enter the infix expression: ");
    scanf("%s", exp);

    char* postfix = infixToPostfix(exp);
    if (postfix == NULL)
        printf("Invalid infix expression\n");
    else
        printf("Postfix expression: %s\n", postfix);

    return 0;
}
