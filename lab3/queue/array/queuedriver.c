#include "queue.h"
#include <stdio.h>

Element iftoe(int i,float f){
	Element ele;
	ele.int_value = i;
	ele.float_value = f;
	return ele;
}

int main(void) {
    Queue* q = createQueue();

    // Enqueue elements
    for (int i = 1; i <= 5; i++) {
        float float_val = i * 1.1;
        enqueue(q, iftoe(i, float_val));
    }

    // Print the elements and their sizes
    printf("Queue size: %d\n", size(q));

    printf("Front element: ");
    Element* front_element = front(q);
    if (front_element != NULL) {
        printf("Integer: %d, Float: %.2f\n", front_element->int_value, front_element->float_value);
    } else {
        printf("Queue is empty\n");
    }

    // Dequeue elements
    while (!isEmpty(q)) {
        printf("Dequeued element: Integer: %d, Float: %.2f\n", front(q)->int_value, front(q)->float_value);
        dequeue(q);
    }

    // Destroy the queue
    destroyQueue(q);

    return 0;
}
