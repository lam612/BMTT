CC = gcc
all: client.o server.o rsa.c
	$(CC) -o client client.c rsa.c -lm
	$(CC) -o server server.c
clean:
	rm *.o client server
