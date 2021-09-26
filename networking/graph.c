// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdint.h>
#include "graph.h"

void graph_create(graph *g, int nodes){
    g->nodes = (char *)calloc(nodes, sizeof(char));
    g->links = (link *)calloc(nodes * nodes, sizeof(link));
}
