main : main.o queue.o
	$(CC) $^ -o $@
%.o:%.c
	$(CC) -c -o $@ $<
clean:
	rm -rf *.o main

