CC=gcc
all: hello
hello: main.c
	$(CC) -o main main.c

clean :
	rm -f main stack queue