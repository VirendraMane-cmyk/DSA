runDriver:	linked_list.o	stack.o	calculator.o
	gcc	-o	runDriver	stack.o	linked_list.o	calculator.o
linked_list.o:	linked_list.c	linked_list.h
	gcc	-c	linked_list.c
stack.o:	stack.c	stack.h	linked_list.h
	gcc	-c	stack.c
calculator.o:	calculator.c	stack.h
	gcc	-c	calculator.c