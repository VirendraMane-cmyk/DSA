runStackWithArray:	stackDriver.o	stack.o	heap_usage.o
	gcc	-o	runStackWithArray	stackDriver.o	stack.o
	@echo running the stack with array

stackDriver.o:	stackDriver.c	stack.h
	gcc	-c	stackDriver.c
stack.o:	stack.c	stack.h
	gcc	-c	stack.c
heap_usage.o:	heap_usage.c	heap_usage.h
	gcc	-c	heap_usage.c
clean:	rm	-f	*.o	runStackWithArray
