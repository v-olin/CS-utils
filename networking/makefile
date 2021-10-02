
CC=gcc
CFLAGS=-Wall -Wpedantic -Wextra -g

build: clean build-dijkstra

build-dijkstra: dijkstra.o graph.o
	$(CC) debug/dijkstra.o debug/graph.o $(CFLAGS)

dijkstra.o: dijkstra.c
	$(CC) -c dijkstra.c -o debug/dijkstra.o $(CFLAGS)

graph.o: graph.c
	$(CC) -c graph.c -o debug/graph.o $(CFLAGS)

clean:
	rm *.out
	rm -rf debug
	mkdir debug