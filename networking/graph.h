#ifndef GRAPH_H
#define GRAPH_H

#include <stdint.h>

#define INFINITY    ((uint8_t) 0xFF)

typedef struct {
    char name;
    uint8_t cost;
} vertex;

typedef struct {

} vertex_set;

/* Old implementation
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

void graph_create(graph *g, char *nodes);
void graph_from_matrix(graph *g, uint8_t *matrix);
void solve_graph(graph *g);
*/


#endif