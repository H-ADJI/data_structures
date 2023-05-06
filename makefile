CC=gcc
all: build run clean
run: data_structures
	./data_structures
build: main.o stack.o queue.o linked_list.o hash_map.o
	$(CC) queue.o main.o stack.o linked_list.o hash_map.o -o data_structures
main:  main.c
	$(CC) -c main.c
stack:  stack.c
	$(CC) -c stack.c
linked_list:  linked_list.c
	$(CC) -c linked_list.c
queue:  queue.c
	$(CC) -c queue.c
hash_map:  hash_map.c
	$(CC) -c hash_map.c
clean :
	rm -f *.o data_structures
