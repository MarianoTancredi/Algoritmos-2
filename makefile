CFLAGS=-g -O2 -std=c99 -Wall -Wconversion -Wtype-limits -Werror -I src
VFLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2

valgrind: pruebas
	valgrind $(VFLAGS) ./pruebas 2>&1

valgrind-server: server
	valgrind $(VFLAGS) ./server 2>&1

pruebas:
	gcc $(CFLAGS) -o pruebas pruebas.c src/*.c 2>&1

server:
	gcc $(CFLAGS) -o server server.c src/*.c 2>&1

clean:
	rm pruebas server 2>&1