#include "stack.h"
#include <stdio.h>

int main(void) {
    STACK myStack = createNewStack();
    int option, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push element\n");
        printf("2. Pop element\n");
        printf("3. Peek element\n");
        printf("4. Check if stack is empty\n");
        printf("5. Print stack\n");
        printf("6. Destroy stack\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter value to push onto the stack: ");
                scanf("%d", &value);
                push(myStack, value);
                break;

            case 2:
                if (pop(myStack)) {
                    printf("Element popped from the stack.\n");
                } else {
                    printf("Stack is empty. Cannot pop.\n");
                }
                break;

            case 3:
                value = peek(myStack);
                if (value != -1) {
                    printf("Top element of the stack: %d\n", value);
                } else {
                    printf("Stack is empty. Cannot peek.\n");
                }
                break;

            case 4:
                if (isStackEmpty(myStack)) {
                    printf("The stack is empty.\n");
                } else {
                    printf("The stack is not empty.\n");
                }
                break;

            case 5:
                printStack(myStack);
                break;

            case 6:
                destroyStack(myStack);
                printf("Stack destroyed.\n");
                myStack = createNewStack(); // Create a new stack after destroying
                break;

            case 7:
                printf("Exiting program.\n");
                destroyStack(myStack); // Clean up before exiting
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (option != 7);

    return 0;
}
