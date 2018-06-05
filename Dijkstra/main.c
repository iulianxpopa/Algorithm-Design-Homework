///\file main.c
///\brief Main file where all the functions are called from.
///\author Popa Ionut Iulian


#include <stdio.h>
#include <conio.h>
#define INFINITY 99999

#include "generate.h"
#include "print.h"
#include "dijkstra.h"

/*
#include "generate.c"
#include "print.c"
#include "dijkstra.c"
*/

///\fn int main
int main(){
    ///\brief Main function that takes user input to establish the start node and the end node of the path which want to be determined.
    int **matrix, nodes_number, start_node, end_node;
  	matrix = GenerateRandGraph(matrix, &nodes_number);

  	print_matrix(matrix, nodes_number);

    ///\brief start_node The node in which the search starts.
    printf("\nEnter the starting node:");
    scanf("%d", &start_node);
    ///\brief end_node The node in which the search ends.
    printf("\nEnter the ending node:");
    scanf("%d", &end_node);

    dijkstra(matrix, nodes_number, start_node, end_node);

    getch();
    return 0;
}
