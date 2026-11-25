CC=gcc
CFLAGS=-I.

tcp: tcpserver tcpclient

udp: udpserver udpclient

tcpserver: tcpserver.c
	mkdir -p bin
	$(CC) tcpserver.c -o bin/tcpserver $(CFLAGS)

tcpclient: tcpclient.c
	mkdir -p bin
	$(CC) tcpclient.c -o bin/tcpclient $(CFLAGS)

udpserver: udpserver.c
	mkdir -p bin
	$(CC) udpserver.c -o bin/udpserver $(CFLAGS)

udpclient: udpclient.c
	mkdir -p bin
	$(CC) udpclient.c -o bin/udpclient $(CFLAGS)
	
clear:
	rm -rf bin