checkPerformance: cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	gcc -o checkPerformance cgStackDriver.o stack_ll.o heap_usage.o linked_list.o
	@echo running the performance check

cgStackDriver.o: cgStackDriver.c stack.h
	gcc -c cgStackDriver.c

stack_ll.o: stack_ll.c stack.h linked_list.h
	gcc -c stack_ll.c

heap_usage.o: heap_usage.c heap_usage.h
	gcc -c heap_usage.c

linked_list.o: linked_list.c linked_list.h
	gcc -c linked_list.c

clean:
	rm -f *.o checkPerformance
