// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "graph.h"

void graph_create(graph *g, uint32_t nodes){
    g->node_count = nodes;
    g->nodes = (node *)malloc(nodes * sizeof(node));
    for (int i = 0; i < nodes; i++){
        g->nodes[i].links = (link *)malloc(nodes * sizeof(link));
    }
}

void graph_from_matrix(graph *g, uint8_t *matrix){
    uint32_t i, len = g->node_count * g->node_count;
    for (i = 0; i < len; i++){
        printf("Next: %u", matrix[i + g->node_count]);
    }
}
