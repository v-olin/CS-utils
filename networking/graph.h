#ifndef GRAPH_H
#define GRAPH_H

typedef struct {
    char src;
    char dst;
    uint8_t cost;
} link;

typedef struct {
    char *nodes;
    link *links;
} graph;

void graph_create(graph *g, int nodes);

#endif