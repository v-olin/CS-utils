// dijsktra.c

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

FILE *open_file(char *file);
uint8_t count_nodes(FILE *fptr, char *nodes);
uint32_t read_matrix(FILE *fptr, uint8_t *matrix);
// void setup_graph(graph *g, char *nodes, uint8_t *matrix);

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("ERROR: Too few arguments");
        exit(-1);
    }
    
    FILE *fptr = open_file(argv[1]);

    char *nodes = (char *)malloc(26 * sizeof(char));
    count_nodes(fptr, nodes);
    
    uint8_t *matrix = (uint8_t *)malloc(strlen(nodes) * strlen(nodes) * sizeof(uint8_t));
    read_matrix(fptr, matrix);

    fclose(fptr);

    return 0;
}

FILE *open_file(char *file){
    FILE *fptr;

    if ((fptr = fopen(file, "r")) == NULL){
        printf("ERROR: Couldn't open file %s", file);
        exit(1);
    }

    return fptr;
}

uint8_t count_nodes(FILE *fptr, char *nodes){
    char c;
    bool begin_count = false;
    uint8_t node_index = 0;
    while (1){
        c = fgetc(fptr);
        if (begin_count == false){
            if (c == 'N')
                begin_count = true;
        }
        else {
            if (c == '\n')
                break;
            else if (c != ';')
                nodes[node_index++] = c;
        }
    }
    nodes[node_index] = '\0';

    printf("Nodes found:\t%ld\n", strlen(nodes));

    return strlen(nodes);
}

uint32_t read_matrix(FILE *fptr, uint8_t *matrix){
    char c;
    uint32_t i = 0;
    while(1){
        c = fgetc(fptr);
        if (feof(fptr))
            break;

        if (c == '-'){
            matrix[i++] = INFINITY;
        }
        else if (c >= '0' && c <= '9'){
            matrix[i++] = (uint8_t)(c - 48);
        }
    }
    return i;
}
