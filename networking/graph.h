#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

#define INFINITY    ((uint8_t) 0xFF)

typedef struct {
    char dst;
    uint8_t cost;
} link;

typedef struct {
    char name;
    char link_count;
    link *links;
} node;

typedef struct {
    char node_count;
    node *nodes;
} graph;

void graph_create(graph *g, uint32_t nodes);
void graph_from_matrix(graph *g, char *nodes, uint8_t *matrix, uint32_t matrix_size);

#endif