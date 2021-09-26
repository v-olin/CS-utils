
CC=gcc
CFLAGS=-Wall -Wpedantic -Wextra -g

build: clean build-dijsktra

build-dijsktra: dijsktra.o graph.o
	$(CC) debug/dijsktra.o debug/graph.o $(CFLAGS)

dijsktra.o: dijsktra.c
	$(CC) -c dijsktra.c -o debug/dijsktra.o $(CFLAGS)

graph.o: graph.c
	$(CC) -c graph.c -o debug/graph.o $(CFLAGS)

clean:
	rm -rf debug
	mkdir debug