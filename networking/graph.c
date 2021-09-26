// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdint.h>
#include "graph.h"

void graph_create(graph *g, int nodes){
    g->node_count = nodes;
    g->nodes = (node *)malloc(nodes * sizeof(node));
    for (int i = 0; i < nodes; i++){
        g->nodes[i].links = (link *)malloc(nodes * sizeof(link));
    }
}

void graph_from_matrix(graph *g, uint8_t *matrix){
    
}
