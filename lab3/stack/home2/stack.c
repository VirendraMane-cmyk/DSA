#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

STACK createNewStack() {
    STACK stack = (STACK)malloc(sizeof(stack));
    stack->count = 0;
    stack->list = createNewList();
    return stack;
}

void push(STACK stack, int data) {
    insertNodeAtIndex(0, stack->list, createNewNode(data));
    stack->count++;
}

bool pop(STACK stack) {
    if (!isStackEmpty(stack)) {
        deleteNodeAtIndex(0, stack->list);
        stack->count--;
        return true;
    }
    return false;
}

int peek(STACK stack) {
    if (!isStackEmpty(stack)) {
        return stack->list->head->val;
    }
    return -1; // Return a sentinel value indicating an empty stack or error
}

bool isStackEmpty(STACK stack) {
    return (stack == NULL || stack->count == 0);
}

int stackSize(STACK stack) {
    if (stack != NULL) {
        return stack->count;
    }
    return 0;
}

void printStack(STACK stack) {
    if (stack != NULL) {
        printf("Stack: ");
        printList(stack->list);
    }
}

void destroyStack(STACK stack) {
    if (stack != NULL) {
        destroyList(stack->list);
        free(stack);
    }
}
