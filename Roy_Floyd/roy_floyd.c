///\file dijkstra.c
///\brief File which contains the processing actions.
///\author Popa Ionut Iulian


#include "roy_floyd.h"
#define INFINITY 99999


///\fn int roy_floyd( int **roy_floyd_matrix, int *nodes_number)

void roy_floyd(int **roy_floyd_matrix, int nodes_number){
    ///\brief This method will generate an matrix to find the shortest path and it will be stored in **roy_floyd_matrix.
    ///\param int **roy_floyd_matrix the matrix generated
    ///\param int nodes_number the number of graph nodes.
    int i, j, k;
    for(k = 1; k <= nodes_number; k++){
        for(i = 1; i <= nodes_number; i++){
            for(j = 1; j <= nodes_number; j++){
                if (roy_floyd_matrix[i][j] > roy_floyd_matrix[i][k] + roy_floyd_matrix[k][j]){
                    roy_floyd_matrix[i][j] = roy_floyd_matrix[i][k] + roy_floyd_matrix[k][j];
                }
            }
        }
    }
}
