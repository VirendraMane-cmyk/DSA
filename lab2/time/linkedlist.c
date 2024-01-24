#include "linkedlist.h"

RECORD createNewRecord(double cg,char *ID){
    RECORD record = (RECORD)malloc(sizeof(struct record));

    // Check if memory allocation is successful
    if (record == NULL) {
        // Handle the error (e.g., return NULL, print an error message, etc.)
        return NULL;
    }

    // Allocate memory for the ID string and copy the provided string
    record->ID = strdup(ID);

    // Check if memory allocation is successful
    if (record->ID == NULL) {
        // Handle the error (e.g., free previously allocated memory, return NULL, etc.)
        free(record);
        return NULL;
    }

    // Set the cgpa field
    record->CGPA = cg;

    // Return the pointer to the created record
    return record;
}

LIST createNewList() {
    LIST myList = (LIST)malloc(sizeof(struct linked_list));
    myList->count = 0;
    myList->head = NULL;
    return myList;
}

NODE createNewNode(RECORD record) {
    NODE node = (NODE)malloc(sizeof(struct node));
    node->record = record;
    node->next = NULL;
    return node;
}

void printRecord(RECORD record) {
    if (record != NULL) {
        printf("CGPA: %.2f\n", record->CGPA);
        printf("ID: %s\n", record->ID);
    } else {
        printf("Record is NULL\n");
    }
}


void printList(LIST l1) {
    NODE temp = l1->head;
    printf("[HEAD] ->");
    while (temp != NULL) {
        printRecord(temp->record);
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
void search(RECORD record,LIST list){
    NODE curr = list->head;
    int index = 0;
    while(curr != NULL){
        if((curr->record->CGPA == record->CGPA) && (curr->record->ID == record->ID)){
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

void insert(RECORD record, LIST list) {
    // Create a new node with the provided record
    NODE newNode = createNewNode(record);

    // Check if node creation was successful
    if (newNode == NULL) {
        // Handle the error (print an error message, return, etc.)
        return;
    }

    // Set the next pointer of the new node to the current head of the list
    newNode->next = list->head;

    // Update the head of the list to be the new node
    list->head = newNode;

    // Increment the count of elements in the list
    list->count++;
}

void fileInput(char *location,LIST list) {
    FILE* fptr;

    // Open the file for reading
    fptr = fopen(location, "r");

    // Check if the file was opened successfully
    if (fptr == NULL) {
        printf("Error opening the file.\n");

        return;
    }

    while(!feof(fptr)){
        char id[100];

        double cg;

        fscanf(fptr,"[^,],%lf",id,&cg);

        RECORD r = createNewRecord(cg,id);

        insert(r,list);
        
    }

    // Now you can read from the file using fscanf or other file reading functions

    

    // Close the file when done
    fclose(fptr);
}

