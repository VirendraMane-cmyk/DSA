runPerformanceArray:	cgQueueDriver.o	queue.o	heap_usage.o
	gcc	-o	runPerformanceArray	cgQueueDriver.o	queue.o	heap_usage.o
cgQueueDriver.o:	cgQueueDriver.c	queue.h	heap_usage.h
	gcc -c	cgQueueDriver.c
queue.o:	queue.c	queue.h
	gcc	-c	queue.c	
heap_usage.o:	heap_usage.c	heap_usage.h
	gcc	-c	heap_usage.c