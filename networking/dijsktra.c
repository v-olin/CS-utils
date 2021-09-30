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

int main(int argc, char *argv[]){
    // check for correct amount of arguments
    if (argc != 2){
        printf("ERROR: Too few arguments");
        exit(-1);
    }
    
    // open file
    FILE *fptr = open_file(argv[1]);

    char *nodes = (char *)malloc(26 * sizeof(char));
    uint8_t node_count = count_nodes(fptr, nodes);
    // create and read matrix
    uint8_t *matrix = (uint8_t *)malloc(node_count * node_count * sizeof(uint8_t));
    uint32_t matrix_size = read_matrix(fptr, matrix);

    fclose(fptr);

    // create and malloc space for graph
    graph g;
    graph_create(&g, node_count);
    // read matrix to graph
    graph_from_matrix(&g, nodes, matrix, matrix_size);

    return 0;
}

FILE *open_file(char *file){
    FILE *fptr;

    // try to open file
    if ((fptr = fopen(file, "r")) == NULL){
        printf("ERROR: Couldn't open file %s", file);
        exit(1);
    }

    // return file pointer
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
            // printf("Val: %u\n", matrix[i - 1]);
        }
        else if (c >= '0' && c <= '9'){
            matrix[i++] = (uint8_t)(c - 48);
            // printf("Val: %u\n", matrix[i - 1]);
        }
    }
    return i;
}

