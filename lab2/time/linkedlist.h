#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct record* RECORD;

struct record
{
    double CGPA;
    char *ID;
};

typedef struct node* NODE;

struct node
{
    RECORD record;
    NODE next;
};

typedef struct linked_list* LIST;

struct linked_list
{   
    int count;
    NODE head;
};

//Creates a new record and returns the pointer to it
RECORD createNewRecord(double cg,char *ID);

//Create new linked list and returns the pointer to that list
LIST createNewList();

//Creates a node and returns the pointer to that node
NODE createNewNode(RECORD record);

//Prints the record
void printRecord(RECORD record);

//Prints the contents of the list
void printList(LIST l1);

//Deletes the element at the given index if the index is correct
void deleteAt(int index,LIST list);

//Searches for an element and returns its zero indexed position
void search(RECORD record,LIST list);

//Deletes the element at the first index
void deleteFirst(LIST list);

//Reverse the linked list
void reverseList(LIST list);

//Checks if the given linkedlist contain a cycle
bool hasCycle(LIST list);

//Inserts an element to the head of the list
void insert(RECORD record,LIST list);

//Takes input from a give file
void fileInput(char *location,LIST list);
