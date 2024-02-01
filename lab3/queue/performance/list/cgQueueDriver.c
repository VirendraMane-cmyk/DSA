#include "queue.h"
#include "heap_usage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

Element iftoe(int i, float f);

struct timeval t1, t2;

double time_taken1, time_taken2;

int main(int argc, char *argv[]) {
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file");
        exit(1);
    }

    char *line = malloc(100);

    // Initialize a queue and time-performance variable
    Queue *q = createQueue();
    gettimeofday(&t1, NULL);

    int score = 0;
    float cg = 0;
    int i = 0;

    while (fgets(line, 100, fp) != NULL) {
        char *token;
        token = strtok(line, ",");
        score = atoi(token);
        token = strtok(NULL, ",");
        cg = atof(token);

        /*
            Write code to enqueue the score and cg values into the queue while tracking the time and heap performance
        */
        Element ele = iftoe(score, cg);
        enqueue(q, ele);
        i++;
    }
    fclose(fp);

    gettimeofday(&t2, NULL);
    time_taken1 = (t2.tv_sec - t1.tv_sec) * 1e6 + (t2.tv_usec - t1.tv_usec); // Microseconds

    /*
        Write code to print the time taken and heap space utilized for enqueuing the values into the queue
    */
    printf("The time taken for the insertion process is %.2f microseconds\n", time_taken1);
    printf("The heap space utilized is: %zu\n", heapMemoryAllocated);

    /*
        Write code to empty the queue and print and measure the time taken for the emptying process
    */
    gettimeofday(&t1, NULL);
    while (!isEmpty(q)) {
        dequeue(q);
    }
    destroyQueue(q);
    gettimeofday(&t2, NULL);

    time_taken2 = (t2.tv_sec - t1.tv_sec) * 1e6 + (t2.tv_usec - t1.tv_usec);

    printf("The time required to empty the queue is: %.2f microseconds\n", time_taken2);

    /*
        Print the total time taken for the entire process and the maximum heap usage throughout the process
    */
    printf("The total time taken for the entire process is: %0.2f microseconds\n", time_taken1 + time_taken2);
}
Element iftoe(int i, float f) {
    Element e;
    e.int_value = i;
    e.float_value = f;
    return e;
}
