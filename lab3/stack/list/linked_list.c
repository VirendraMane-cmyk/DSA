#include "linked_list.h"
#include <stdlib.h>

LIST createNewList(){
    LIST mylist = (LIST)malloc(sizeof(linked_list));
    mylist->count = 0;
    mylist->head = NULL;
    return mylist;
}

NODE createNewNode(Element data){
    NODE node = (NODE)malloc(sizeof(node));

    node->data = data;

    node->next = NULL;

    return node;
}

void insertNodeIntoList(NODE node,LIST list){
    if(list->head == NULL){
        list->head = node;
    }
    else{
        NODE temp = list->head;

        list->head = node;

        node->next = temp;
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

        free(first);
    }
}

void destroyList(LIST list){
    NODE curr = list->head;

    NODE next;

    while(curr != NULL){
        next = curr->next;

        free(curr);

        curr = next;
    }

    free(list);
}