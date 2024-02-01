#include "queue.h"
#include <stdlib.h>

#define MAX_SIZE 1000

struct Queue{
    int front;
    int rear;
    int size;
    Element data[MAX_SIZE];
};

Queue* createQueue(){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    return q;
}

bool enqueue(Queue *queue,Element element){
    if(queue->size == MAX_SIZE){
        return false;
    }
    queue->rear = (queue->rear + 1)%MAX_SIZE;

    if(queue->front == -1){
        queue->front = 0;
    }

    queue->data[queue->rear] = element;
    queue->size++;
    return true;
}

bool dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        return false;
    }

    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }

    queue->size--;
    return true;
}

Element* front(Queue *queue){
    if(isEmpty(queue)){
        return NULL;
    }
    return &(queue->data[queue->front]);
}

int size(Queue* queue){
    return queue->size;
}

bool isEmpty(Queue* queue){
    return  (queue->size == 0);
}

void destroyQueue(Queue *queue){
    free(queue);
    return;
}