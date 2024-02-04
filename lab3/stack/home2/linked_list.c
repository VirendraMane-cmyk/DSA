#include "linked_list.h"
#include  <stdio.h>

LIST createNewList(){
    LIST list = (LIST)malloc(sizeof(linked_list));
    if(list == NULL){
        return NULL;
    }
    list->count = 0;
    list->head = NULL;

    return list;
}

NODE createNewNode(int val){
    NODE node = (NODE)malloc(sizeof(node));
    if(node == NULL){
        return NULL;
    }
    node->val = val;
    node->next = NULL;

    return node;
}

LIST insertNodeAtIndex(int index, LIST list, NODE node) {
    // Case 1 -> if linked list is empty
    if (list == NULL) {
        return NULL;
    }

    // Inserting will be done based on zero indexing
    if (list->count == 0 || index == 0) {
        node->next = list->head;
        list->head = node;
    } else {
        NODE temp = list->head;
        int count = 0;

        // Move to the node before the insertion point
        while (temp != NULL && count < index - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            // Index out of bounds
            return list;
        }

        // Insert the new node
        node->next = temp->next;
        temp->next = node;
    }

    list->count++;
    return list;
}


LIST deleteNodeAtIndex(int index, LIST list) {
    if (list == NULL) {
        return NULL;
    }

    if (list->count == 0) {
        return list; // Nothing to delete
    }

    // If index == 0
    if (index == 0) {
        NODE temp = list->head;
        list->head = list->head->next;
        free(temp);
    } else {
        NODE curr = list->head;
        NODE prev = NULL;

        int count = 0;
        while (curr != NULL && count < index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == NULL) {
            return list; // Index out of bounds
        }

        // If index is not 0, adjust the previous node's next pointer
        prev->next = curr->next;

        free(curr);
    }

    list->count--;
    return list;  // Return the updated list after deletion
}


bool isListEmpty(LIST list){
    return (list->count == 0);
}

void printList(LIST list) {
    if (list == NULL) {
        return;
    }

    if (list->count == 0) {
        printf("[]\n");
    } else {
        printf("HEAD -> [");
        NODE temp = list->head;

        while (temp != NULL) {
            printf("%d", temp->val);

            if (temp->next != NULL) {
                printf(" -> ");
            }

            temp = temp->next;
        }

        printf("]\n");
    }
}

void destroyList(LIST list){
    if(list == NULL){
        return;
    }

    if(list->count == 0){
        free(list);
        return;
    }

    NODE curr = list->head;
    NODE next = NULL;

    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(list);

    return;

    
}


