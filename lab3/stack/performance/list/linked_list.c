#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

LIST createNewList(){
    LIST mylist = (LIST)myalloc(sizeof(linked_list));
    mylist->count = 0;
    mylist->head = NULL;
    return mylist;
}

NODE createNewNode(Element data){
    NODE node = (NODE)myalloc(sizeof(node));

    node->data = data;

    node->next = NULL;

    return node;
}

void insertNodeIntoList(NODE node, LIST list) {
    if (list->head == NULL) {
        // If the list is empty, set the new node as the head
        list->head = node;
    } else {
        // If the list is not empty, insert the new node at the beginning
        node->next = list->head;
        list->head = node;
    }

    list->count++;
}
void removeFirstNode(LIST list){
    if(list->count == 0){
        return;
    }
    else{
        NODE first = list->head;
        
        list->head  = first->next;

        list->count--;

        myfree(first);
    }
}

void print(Element ele){
    printf("Score: %d\n",ele.int_value);
    printf("Cg: %f\n",ele.float_value);
}

void printList(LIST list) {
    if (list == NULL) {
        printf("List is NULL\n");
        return;
    }

    NODE current = list->head;

    printf("List elements: ");
    while (current != NULL) {
        print(current->data); // Assuming 'data' is an integer
        current = current->next;
    }

    printf("\n");
}


void destroyList(LIST list) {
    NODE curr = list->head;
    NODE next;

    while (curr != NULL) {
        next = curr->next;
        myfree(curr);
        curr = next;
    }

    myfree(list);
}