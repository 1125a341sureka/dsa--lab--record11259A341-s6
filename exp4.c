#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

double stack[MAX];
int top = -1;

int push(double value) {
    if (top == MAX - 1) {
        return 0;
    }
    stack[++top] = value;
    return 1;
}

int pop(double *value) {
    if (top == -1) {
        return 0;
    }
    *value = stack[top--];
    return 1;
}

int evaluatePostfix(const char postfix[], double *result) {
    top = -1;

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isspace((unsigned char)c)) {
            continue;
        }
        if (isdigit((unsigned char)c)) {
            if (!push(c - '0')) {
                return 0;
            }
        } else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
            double op1, op2, value;
            if (!pop(&op2) || !pop(&op1)) {
                return 0;
            }
            switch (c) {
                case '+': value = op1 + op2; break;
                case '-': value = op1 - op2; break;
                case '*': value = op1 * op2; break;
                case '/':
                    if (op2 == 0.0) {
                        return 0;
                    }
                    value = op1 / op2;
                    break;
                case '^': value = pow(op1, op2); break;
                default: return 0;
            }
            if (!push(value)) {
                return 0;
            }
        } else {
            return 0;
        }
    }

    if (top != 0 || !pop(result)) {
        return 0;
    }
    return 1;
}

int main(void) {
    char postfix[MAX];
    double result;

    printf("Enter postfix expression (single-digit operands, e.g. 23+4*): ");
    if (fgets(postfix, sizeof postfix, stdin) == NULL) {
        printf("Failed to read expression.\n");
        return 1;
    }
    postfix[strcspn(postfix, "\n")] = '\0';

    if (!evaluatePostfix(postfix, &result)) {
        printf("Invalid postfix expression or division by zero.\n");
        return 1;
    }
    printf("Result = %.2f\n", result);
    return 0;
}
