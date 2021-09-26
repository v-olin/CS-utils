#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

#define INFINITY    ((uint8_t) 0xFF)

typedef struct {
    char dst;
    uint8_t cost;
} link;

typedef struct {
    char c;
    char link_count;
    link *links;
} node;

typedef struct {
    char node_count;
    node *nodes;
} graph;

void graph_init(graph *g, int nodes);

#endif