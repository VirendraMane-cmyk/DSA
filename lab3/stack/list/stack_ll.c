#include "stack.h"
#include "linked_list.h"
#include <stdlib.h>

//Stack will contain a pointer to the head of the linked list

struct Stack
{
    LIST list;
    //The top is used just to check empty stack
    int top;
};


Stack *newStack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(stack != NULL){
        stack->list = createNewList();
        stack->top = -1;
    }
    return stack;
}

bool push(Stack *stack, Element element){
    NODE node = (NODE)malloc(sizeof(node));
    if(node == NULL){
        return false;
    }

    node->data = element;
    node->next = NULL;

    insertNodeIntoList(node,stack->list);

    stack->top++;

    return true;
}

Element* top(Stack *stack){
    if(stack->top == -1){
        return NULL;
    }
    return &(stack->list->head->data);
}

bool pop(Stack * stack){
    if(stack->top == -1){
        return false;
    }
    removeFirstNode(stack->list);

    return true;
}

bool isEmpty(Stack* stack){
    if(stack->top == -1){
        return true;
    }

    return false;
}

void freeStack(Stack* stack){
    if(stack != NULL){
        destroyList(stack->list);
    }

    free(stack);

    return;
}


