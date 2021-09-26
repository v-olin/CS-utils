// dijsktra.c

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include "graph.h"

FILE *open_file(char *file);
// uint8_t **read_matrix(FILE *fptr);
void read_matrix(FILE *fptr);

int main(int argc, char *argv[]){
    if (argc != 2){
        printf("ERROR: Too few arguments");
        exit(-1);
    }
    
    FILE *fptr = open_file(argv[1]);

    read_matrix(fptr);

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

void read_matrix(FILE *fptr){
    char c;
    while(1){
        c = fgetc(fptr);
        if (feof(fptr))
            break;
        printf("%c", c);
    }
    printf("\n");
}

