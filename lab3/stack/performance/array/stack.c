#include "stack.h"
#include "element.h"
#include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 1000
//Defines the maxmimum size of the stack

struct Stack
{
    int top;
    Element data[STACK_SIZE];
};

Stack* newStack(){
    Stack* s = (Stack*)myalloc(sizeof(Stack));

    if(s != NULL)
    {
        s->top = -1;
    }
    return s;
}

bool push(Stack * s,Element e){
    if(s->top == STACK_SIZE - 1){
        return false;
    }
    s->data[++(s->top)] = e;
    return true;
}

Element* top(Stack* stack){
    Element* res = (Element*)myalloc(sizeof(Element));
    if(stack->top == -1){
        return res;
    }
    //The -> deferences memory can be used to directly  access members
    //the members of a struct
    *res = stack->data[stack->top];

    return res;
}

bool isEmpty(Stack *stack){
    if(stack->top == -1){
        return true;
    }

    return false;
}

bool pop(Stack *stack){
    //Check if the stack is empty
    if(stack->top == -1){
        return false;
    }
    (stack->top)--;
    return true;
}

void freeStack(Stack *stack){
    myfree(stack);
}
