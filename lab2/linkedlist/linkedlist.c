#include "linkedlist.h"

LIST createNewList() {
    LIST myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE createNewNode(int value) {
    NODE node = (NODE)malloc(sizeof(struct node));
    node->ele = value;
    node->next = NULL;
    return node;
}

void insertAfter(int searchEle, NODE n1, LIST l1) {
    if (l1->head == NULL) {
        l1->head = n1;
        n1->next = NULL;
        l1->count++;
    } else {
        NODE temp = l1->head;
        NODE prev = temp;
        while (temp != NULL) {
            if (temp->ele == searchEle) break;
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            printf("Element not found\n");
            return;
        } else {
            if (temp->next == NULL) {
                temp->next = n1;
                n1->next = NULL;
                l1->count++;
            } else {
                prev = temp;
                temp = temp->next;
                prev->next = n1;
                n1->next = temp;
                l1->count++;
            }
            return;
        }
    }
    return;
}

void printList(LIST l1) {
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL) {
        printf(" %d ->", temp->ele);
        temp = temp->next;
    }
    printf(" [NULL]\n");
}

void deleteAt(int index,LIST list){
    if(index >= list->count || index < 0){
        printf("Index out of bounds\n");
        return;
    }

    NODE curr = list->head;
    NODE prev = NULL;

    if(index == 0){
        list->head = curr->next;
    }else{
        int tempindex = 0;
        while(tempindex != index){
            prev = curr;
            curr = curr->next;
            tempindex++;
        }

        prev->next = curr->next;
    }

    list->count--;
    free(curr);

    return;
}
void search(int val,LIST list){
    NODE curr = list->head;
    int index = 0;
    while(curr != NULL){
        if(curr->ele == val){
            return index;
        }
        
        curr = curr->next;

        index++;
    }

    if(curr == NULL){
        printf("Element does not exist in the list\n");
        return;
    }
    return index;
}

void deleteFirst(LIST list){
    return deleteAt(0,list);
}

void reverseList(LIST list){
    if(list->count == 0 || list->count == 1){
        return;
    }

    NODE curr = list->head;
    NODE prev = NULL;
    NODE next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    //Update the head pointer of the list
    list->head = prev;
}

bool hasCycle(LIST list){
    if(list->count == 0 || list->count == 1){
        return false;
    }

    NODE fast = list->head;
    NODE slow = list->head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            return true;
        }
    }

    return false;
}


