// dijsktra.c

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "graph.h"

FILE *open_file(char *file);
uint32_t read_matrix(uint8_t *matrix, FILE *fptr);

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("ERROR: Too few arguments");
        exit(-1);
    }
    
    FILE *fptr = open_file(argv[1]);

    uint8_t *matrix;
    uint8_t node_count = read_matrix(matrix, fptr);

    graph g;
    graph_create(&g, node_count);

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

uint32_t read_matrix(uint8_t *matrix, FILE *fptr){
    char c;
    bool begin_matrix = false;
    uint8_t node_count = 0;
    char *nodes = (char *)calloc(26, sizeof(char));
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

    matrix = (uint8_t *)malloc((node_count * (node_count + 1)) * sizeof(uint8_t));

    uint32_t i = 0;

    for (i = 0; i < strlen(nodes); i++){
        matrix[i] = nodes[i];
    }

    free(nodes);

    while(1){
        c = fgetc(fptr);
        if (feof(fptr))
            break;

        if (c == '-')
            matrix[i++] = INFINITY;
        else if (c >= '0' && c <= '9'){
            matrix[i++] = (uint8_t)(c - 48);
        }
    }

    fclose(fptr);
    return node_count;
}

