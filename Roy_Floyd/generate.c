///\file generate.c
///\brief File which contains the random generator.
///\author Popa Ionut Iulian

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "generate.h"
#define INFINITY 99999


///\fn int **GenerateRandGraph( int **matrix, int *nodes_number)

int **GenerateRandGraph( int **matrix, int *nodes_number){
    ///\brief This method will generate an adjacency matrix and it will be stored in **matrix.
    ///\param int **matrix graph's adjacency matrix.
    ///\param int nodes_number the number of graph nodes.
    srand(time(0));

	int i, j;

    int n = 5 + rand() % 15;
    *nodes_number =  n;

    ///\brief Resize matrix
    matrix = (int**)calloc(n + 1, sizeof(int));
    for(i = 1; i <= n; i++){
         matrix[i] = (int *)calloc(n + 1, sizeof(int));
    }

    ///\brief Generate random costs
	for(i = 1; i <= n; i++ ){
	     for(j = 1 ; j <= n ; j++){
            int aux_cost = 1 + rand() % 1000;
            matrix[i][j] = aux_cost;
            matrix[j][i] = aux_cost;
	     }
	}

    ///\brief Main diagonal
	for(i = 1; i <= n; i++){
        matrix[i][i] = INFINITY;
    }

    return matrix;
}
