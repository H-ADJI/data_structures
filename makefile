CC=gcc
all: build run clean
run: data_structures
	./data_structures
build: main.o binary_tree.o stack.o queue.o linked_list.o hash_map.o
	$(CC) binary_tree.o queue.o main.o stack.o linked_list.o hash_map.o -o data_structures
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
binary_tree:  binary_tree.c
	$(CC) -c binary_tree.c
clean :
	rm -f *.o data_structures
