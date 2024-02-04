#include "stack.h"
#include <stdio.h>
#include <string.h>
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        // Handle division by zero error or return a sentinel value
        // For simplicity, returning 0 in case of division by zero
        return 0;
    }
}

int main(int argc, char** argv) {
    // Ignore the first argument string
    printf("%d\n", argc);
    STACK stack = createNewStack();
    int len = strlen(argv[1]);

    int res = 0;

    for (int i = 0; i < len; i++) {
        char curr = argv[1][i];
        if (curr == ' ') {
            continue;
        }

        if (curr != '+' && curr != '-' && curr != '/' && curr != '*') {
            push(stack, curr - '0');
        } else {
            int val1 = peek(stack);
            pop(stack);
            int val2 = peek(stack);
            pop(stack);

            switch (curr) {
                case '+':
                    res = add(val1, val2);
                    break;
                case '-':
                    res = subtract(val1, val2);
                    break;
                case '/':
                    res = divide(val1, val2);
                    break;
                case '*':
                    res = multiply(val1, val2);
                    break;
            }

            push(stack, res);
        }
    }

    // Print the final result
    printf("Result: %d\n", peek(stack));

    // Don't forget to destroy the stack
    destroyStack(stack);

    return 0;
}