///\file main.c
///\brief Main file where all the functions are called from.
///\author Popa Ionut Iulian

#include <stdio.h>
#include <conio.h>
#define INFINITY 99999

#include "generate.h"
#include "print.h"
#include "roy_floyd.h"

/*
#include "generate.c"
#include "print.c"
#include "roy_floyd.c"
*/

///\fn int main
int main(){

    ///\brief Main function that takes user input to establish the start node and the end node of the path which want to be determined.
    int i, j;

    int **matrix, nodes_number, start_node, end_node;
    int **roy_floyd_matrix;
  	matrix = GenerateRandGraph(matrix, &nodes_number);

  	print_matrix(matrix, nodes_number);

    ///Copying matrix "matrix" in "roy_floyd_matrix.
    roy_floyd_matrix = (int**)calloc(nodes_number + 1, sizeof(int));
    for(i = 1; i <= nodes_number; i++){
        roy_floyd_matrix[i] = (int *)calloc(nodes_number + 1, sizeof(int));
        for(j = 1; j <= nodes_number; j++){
            roy_floyd_matrix[i][j] = matrix[i][j];
        }
    }

    /// start_node The node in which the search starts.
    printf("\nEnter the starting node:");
    scanf("%d", &start_node);
    /// end_node The node in which the search ends.
    printf("\nEnter the ending node:");
    scanf("%d", &end_node);


    roy_floyd(roy_floyd_matrix, nodes_number);
    show_path(roy_floyd_matrix, nodes_number, start_node, end_node, matrix);


    return 0;
}
