runStackWithList:	stackDriver.o	stack_ll.o	linked_list.o	heap_usage.o
	gcc	-o	runStackWithList	stackDriver.o	stack_ll.o	linked_list.o
	@echo running the stack with linked list
stackDriver.o:	stackDriver.c	stack.h
	gcc -c stackDriver.c
stack_ll.o:	stack_ll.c	stack.h
	gcc -c stack_ll.c
linked_list.o:	linked_list.c	linked_list.h
	gcc	-c	linked_list.c
heap_usage.o:	heap_usage.c heap_usage.h 
	gcc	-c	heap_usage.c
clean:	rm -f *.o runStackWithList
