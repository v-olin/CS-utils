// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "graph.h"

// malloc memory for graph with 'nodes' amount of nodes
void graph_create(graph *g, uint32_t nodes){
    g->node_count = nodes;
    g->nodes = (node *)malloc(nodes * sizeof(node));
    for (int i = 0; i < nodes; i++){
        g->nodes[i].links = (link *)malloc(nodes * sizeof(link));
    }
}

// read matrix to graph data
void graph_from_matrix(graph *g, uint8_t *matrix){
    uint32_t i, len = g->node_count * (g->node_count + 1);
    for (i = 0; i < len; i++){
        if (i < g->node_count)
            printf("Next: %d\t%c\n", i, matrix[i]);
        else
            printf("Next: %d\t%u\n",i ,matrix[i]);
    }
}
