// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "graph.h"

// malloc memory for graph with 'nodes' amount of nodes
void graph_create(graph *g, char *nodes){
    g->node_count = strlen(nodes);
    g->nodes = (node *)malloc(g->node_count * sizeof(node));
    for (int i = 0; i < g->node_count; i++){
        g->nodes[i].name = nodes[i];
        g->nodes[i].links = (link *)malloc(g->node_count * sizeof(link));
    }
}

// read matrix to graph data
void graph_from_matrix(graph *g, uint8_t *matrix){
    uint32_t i, n, m, matrix_size = g->node_count * g->node_count;
    for (i = 0; i < matrix_size; i++){
        n = i / g->node_count;
        m = i % g->node_count;
        // these lines are awful
        g->nodes[n].links[m].dst = g->nodes[m].name;
        g->nodes[n].links[m].cost = matrix[i];

        printf("%c -> %c:\t%u\n", g->nodes[n].name, g->nodes[m].name, g->nodes[n].links[m].cost);
    }
}
