// linked_list.h

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>
#include <stdlib.h>

// Structure definitions
struct node {
    int val;
    struct node* next;
};

typedef struct node node;
typedef struct node* NODE;

struct linked_list {
    int count;
    NODE head;
};

typedef struct linked_list linked_list;
typedef struct linked_list* LIST;

// Function declarations
LIST createNewList();

NODE createNewNode(int val);

LIST insertNodeAtIndex(int index, LIST list,NODE node);

LIST deleteNodeAtIndex(int index, LIST list);

void printList(LIST list);

bool isListEmpty(LIST list);

void destroyList(LIST list);

#endif // LINKED_LIST_H
