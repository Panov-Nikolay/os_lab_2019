CC=gcc
CFLAGS=-I.

server: multModul.c multModul.h
	$(CC) server.c multModul.c -o bin/server $(CFLAGS)

client: multModul.c multModul.h
	$(CC) client.c multModul.c -o bin/client $(CFLAGS)

server_IPv6: multModul.c multModul.h
	$(CC) server_IPv6.c multModul.c -o bin/server_IPv6 $(CFLAGS)

client_IPv6: multModul.c multModul.h
	$(CC) client_IPv6.c multModul.c -o bin/client_IPv6 $(CFLAGS)
	
clear:
	rm bin/server bin/client bin/server_IPv6 bin/client_IPv6