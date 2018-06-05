///\file print.c
///\brief File which contains the printing functions.
///\author Popa Ionut Iulian

#include <stdio.h>
#include "print.h"
#define INFINITY 99999

///\fn void print_matrix(int **matrix, int nodes_number)

void print_matrix(int **matrix, int nodes_number){
    ///\brief This method will print a matrix.
    ///\param int **matrix graph's adjacency matrix.
    ///\param int nodes_number the number of graph nodes.
    int i, j;

    printf("%d nodes\n", nodes_number);

    for(i = 1; i <= nodes_number; i++){
        for(j = 1; j <= nodes_number; j++){
               printf("%5d ",matrix[i][j]%INFINITY);
        }
        printf("\n");
    }
}

///\fn void print_path(int **matrix, int nodes_number, int start_node, int end_node, int distance[], int predecessor[])


void print_path(int **matrix, int nodes_number, int start_node, int end_node, int distance[], int predecessor[]){
    int i, j;
    ///\brief This method will print the path.
    ///\param int **matrix graph's adjacency matrix.
    ///\param int nodes_number the number of graph nodes.
    ///\param int start_node first node pf the path.
    ///\param int end_node last node pf the path.
    ///\param int distance[i] the shortest distance from start node to i
    ///\param int predecessor[i] predecessor of each node

    //print the path and distance between start and end
    printf("\nDistance between node %d and node %d = %d \n", start_node, end_node, distance[end_node]);
    i = end_node;
    printf("\nPath : %d", i);
    while(i != start_node){
        i = predecessor[i];
        printf(" <- %d",i);
    }
    printf("\n\n");

    //print alternative route
    i = end_node;

    printf("\nAlternative path for each consecutive nodes : \n");
    while(i != start_node){
        int min_distance = INFINITY;
        int intermediary = -1;
        for(j = 1; j <= nodes_number; j++){
            if(matrix[i][j] + matrix[j][ predecessor[i] ] < min_distance ){
                min_distance = matrix[i][j] + matrix[j][ predecessor[i] ];
                intermediary = j;
            }
        }
        printf("Intermediary node between %d & %d : %d \n", i, predecessor[i], intermediary);
        i = predecessor[i];
    }
}
