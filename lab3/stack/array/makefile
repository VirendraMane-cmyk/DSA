runStackWithArray:	stackDriver.o	stack.o
	gcc	-o	runStackWithArray	stackDriver.o	stack.o
	@echo running the stack with array

stackDriver.o:	stackDriver.c	stack.h
	gcc	-c	stackDriver.c
stack.o:	stack.c	stack.h
	gcc	-c	stack.c
clean:	rm	-f	*.o	runStackWithArray
