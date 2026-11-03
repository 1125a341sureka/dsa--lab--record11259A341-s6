#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop(void) {
    if (top == -1) {
        return '\0';
    }
    return stack[top--];
}

char peek(void) {
    if (top == -1) {
        return '\0';
    }
    return stack[top];
}

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

int isRightAssociative(char c) {
    return c == '^';
}

int infixToPostfix(const char infix[], char postfix[]) {
    int j = 0;
    top = -1;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isspace((unsigned char)c)) {
            continue;
        }
        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop();
            }
            if (top == -1) {
                return 0;
            }
            pop();
        } else if (precedence(c) != -1) {
            while (top != -1 && peek() != '(' &&
                   (precedence(peek()) > precedence(c) ||
                    (precedence(peek()) == precedence(c) &&
                     !isRightAssociative(c)))) {
                postfix[j++] = pop();
            }
            push(c);
        } else {
            return 0;
        }
    }

    while (top != -1) {
        if (peek() == '(') {
            return 0;
        }
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return 1;
}

int main(void) {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter infix expression: ");
    if (fgets(infix, sizeof infix, stdin) == NULL) {
        printf("Failed to read expression.\n");
        return 1;
    }
    infix[strcspn(infix, "\n")] = '\0';

    if (!infixToPostfix(infix, postfix)) {
        printf("Invalid infix expression.\n");
        return 1;
    }

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
