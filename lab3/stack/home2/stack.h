#include "linked_list.h"
#include <stdbool.h>

// Structure definitions
struct stack {
    int count;
    LIST list; // Use the linked list to store stack elements
};

typedef struct stack stack;
typedef struct stack* STACK;

// Function declarations
STACK createNewStack();
void push(STACK stack, int data);
bool pop(STACK stack);
int peek(STACK stack);
bool isStackEmpty(STACK stack);
int stackSize(STACK stack);
void printStack(STACK stack);
void destroyStack(STACK stack);
