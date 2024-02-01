runQueueWithList:	cgQueueDriver.o	queue.o	linked_list.o	heap_usage.o
	gcc -o runQueueWithList	cgQueueDriver.o	queue.o	linked_list.o	heap_usage.o
	@echo runQueueWithList
cgQueueDriver.o:	cgQueueDriver.c	queue.h
	gcc	-c	cgQueueDriver.c
queue.o:	queue.c	queue.h	heap_usage.h
	gcc	-c	queue.c
linked_list.o:	linked_list.c	heap_usage.h	linked_list.h
	gcc	-c	linked_list.c
heap_usage.o:	heap_usage.c	heap_usage.h 
	gcc	-c	heap_usage.c