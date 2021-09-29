// dijsktra.c

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

FILE *open_file(char *file);
uint8_t read_matrix(uint8_t *matrix, FILE *fptr);

int main(int argc, char *argv[]){
    // check for correct amount of arguments
    if (argc != 2){
        printf("ERROR: Too few arguments");
        exit(-1);
    }
    
    // open file
    FILE *fptr = open_file(argv[1]);

    // create and read matrix
    uint8_t *matrix;
    uint32_t node_count = read_matrix(matrix, fptr);

    // create and malloc space for graph
    graph g;
    graph_create(&g, node_count);
    // read matrix to graph
    graph_from_matrix(&g, matrix);

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

uint8_t read_matrix(uint8_t *matrix, FILE *fptr){
    char c; // tmp
    bool begin_matrix = false; // useless??
    uint8_t node_count = 0; // count nodes in graph
    char *nodes = (char *)calloc(26, sizeof(char)); // store nodes

    // while c isn't newline, read nodes
    while(1){
        c = fgetc(fptr);
        if (begin_matrix == false){
            if (c == 'N')
                begin_matrix = true;
        }
        else {
            if (c == '\n')
                break;
            else if (c != ';' && c != 'N')
                nodes[node_count++] = c;
        }
    }
    nodes[node_count] = '\0';

    // malloc space for matrix
    matrix = (uint8_t *)malloc((node_count * (node_count + 1)) * sizeof(uint8_t));

    uint32_t i = 0;

    for (i = 0; i < strlen(nodes); i++){
        matrix[i] = nodes[i];
    }

    // nodes now stored in matrix
    free(nodes);

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

    fclose(fptr);
    return node_count;
}

