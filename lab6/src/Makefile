CC=gcc
CFLAGS=-I.

server: multModul.c multModul.h
	$(CC) server.c multModul.c -o bin/server $(CFLAGS)

client: multModul.c multModul.h
	$(CC) client.c multModul.c -o bin/client $(CFLAGS)

clear:
	rm bin/server bin/client