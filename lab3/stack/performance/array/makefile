checkPerformance:	cgStackDriver.o	stack.o	heap_usage.o
	gcc	-o	checkPerformance	cgStackDriver.o	stack.o	heap_usage.o
	@echo running the performancecheck
cgStackDriver.o:	cgStackDriver.c
	gcc -c cgStackDriver.c 
stack.o:	stack.c	stack.h
	gcc -c stack.c 
heap_usage.o:	heap_usage.c	heap_usage.h 
	gcc	-c	heap_usage.c
clean:	rm -f *.o checkPerformance