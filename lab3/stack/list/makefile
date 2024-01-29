runStackWithList:	stackDriver.o	stack_ll.o	linked_list.o
	gcc	-o	runStackWithList	stackDriver.o	stack_ll.o	linked_list.o
	@echo running the stack with linked list
stackDriver.o:	stackDriver.c	stack.h
	gcc -c stackDriver.c
stack_ll.o:	stack_ll.c	stack.h
	gcc -c stack_ll.c
linked_list.o:	linked_list.c	linked_list.h
	gcc	-c	linked_list.c
clean:	rm -f *.o runStackWithList
