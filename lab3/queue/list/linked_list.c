#include "linked_list.h"
#include "heap_usage.h"
#include <stdlib.h>

LIST createNewList(){
    LIST mylist = (LIST)myalloc(sizeof(linked_list));
    mylist->count = 0;
    mylist->head = NULL;
    mylist->tail = NULL;
    return mylist;
}

NODE createNewNode(Element data){
    NODE node = (NODE)myalloc(sizeof(node));

    node->data = data;

    node->next = NULL;

    return node;
}

void insertNodeIntoList(NODE node,LIST list){
    if(list->head == NULL){
        //if the list is empty insert the node and update both the pointer
        list->tail = node;
       
    }
    else{
        NODE temp = list->head;
        node->next = temp;
    }

    list->head = node;
    list->count++;
}

void removeFirstNode(LIST list){
    if(list->count == 0){
        return;
    }
    else{
        NODE first = list->head;
        
        list->head  = first->next;

        if(list->count == 1){
            list->tail = NULL;
        }

        list->count--;

        myfree(first);
    }
}

void insertNodeAtEnd(NODE node,LIST list){
    if(list->head == NULL){
        list->head = node;
        list->tail = node;
    }
    else{
        list->tail->next = node;
        list->tail = node;
    }
    list->count++;
}

void destroyList(LIST list){
    NODE curr = list->head;

    NODE next;

    while(curr != NULL){
        next = curr->next;

        myfree(curr);

        curr = next;
    }

    myfree(list);
}