#include "queue.h"
#include "linked_list.h"
#include "heap_usage.h"

struct Queue {
    LIST list;
    int size;
};

Queue *createQueue() {
    Queue *q = (Queue *)myalloc(sizeof(Queue));
    if (q == NULL) {
        // Handle allocation failure
        return NULL;
    }

    q->size = 0;
    q->list = createNewList();
    if (q->list == NULL) {
        // Handle list creation failure
        myfree(q);
        return NULL;
    }

    return q;
}

bool enqueue(Queue *queue, Element element) {
    if (queue == NULL || queue->list == NULL) {
        // Null pointer check
        return false;
    }

    // Enqueueing will add the element at the last
    // of the list
    insertNodeAtEnd(createNewNode(element), queue->list);
    queue->size++;
    return true;
}

bool dequeue(Queue *queue) {
    if (queue == NULL || queue->list == NULL || isEmpty(queue)) {
        // Null pointer check or queue is empty
        return false;
    }

    removeFirstNode(queue->list);
    queue->size--;
    return true;
}

Element *front(Queue *queue) {
    if (queue == NULL || queue->list == NULL || isEmpty(queue)) {
        // Null pointer check or queue is empty
        return NULL;
    }

    return &(queue->list->head->data);
}

int size(Queue *queue) {
    if (queue == NULL) {
        // Null pointer check
        return -1; // or any other appropriate value to indicate an error
    }

    return queue->size;
}

bool isEmpty(Queue *queue) {
    if (queue == NULL) {
        // Null pointer check
        return true; // or any other appropriate value to indicate an error
    }

    return (queue->size == 0);
}

void destroyQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }

    destroyList(queue->list);
    myfree(queue);
    return;
}
