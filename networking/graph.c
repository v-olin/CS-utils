// graph.c
// Graph library for dijsktra.c

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
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
void graph_from_matrix(graph *g, char *nodes, uint8_t *matrix, uint32_t matrix_size){
    uint32_t i, j = 0;
    for (i = 0; i < g->node_count; i++){
        g->nodes[i].name = nodes[i];
        printf("Added node:\t%c\n", g->nodes[i]);
    }

    link l;
    for (i = 0; i < matrix_size; i++){
        // these lines are awful
        g->nodes[i / g->node_count].links[i % g->node_count].dst = nodes[i % g->node_count];
        g->nodes[i / g->node_count].links[i % g->node_count].cost = matrix[i];

        printf("%c -> %c:\t%u\n", 
            g->nodes[i / g->node_count].name, g->nodes[i % g->node_count].name,
            g->nodes[i / g->node_count].links[i % g->node_count].cost);
    }
}
