#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node for stack
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Push
void push(Node** top, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop
int pop(Node** top) {
    if (*top == NULL) {
        printf("Error: Stack Underflow\n");
        return 0;
    }
    Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

// Apply operator
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int main() {
    char expr[100];
    Node* stack = NULL;

    // Read full line (postfix expression)
    fgets(expr, sizeof(expr), stdin);

    char* token = strtok(expr, " \n");

    while (token != NULL) {

        // If operand (number)
        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        // Operator
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result = applyOp(a, b, token[0]);
            push(&stack, result);
        }

        token = strtok(NULL, " \n");
    }

    // Final result
    printf("%d", pop(&stack));

    return 0;
}