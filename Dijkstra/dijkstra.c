///\file dijkstra.c
///\brief File which contains the processing actions.
///\author Popa Ionut Iulian

#include "dijkstra.h"
#include "print.h"
#define INFINITY 99999


///\fn void dijkstra(int **matrix, int nodes_number, int start_node, int end_node)


void dijkstra(int **matrix, int nodes_number, int start_node, int end_node){

    ///\brief This method will calculate the shortest path between any nodes.
    ///\param int **matrix graph's adjacency matrix.
    ///\param int nodes_number The number of graph nodes.
    ///\param int start_node The node which represents the start of the searched path.
    ///\param int end_node The node which represents the end of the searched path.

    int distance[nodes_number + 1];
    ///\brief distance[i] will hold the shortest distance from start node to i
    int predecessor[nodes_number + 1];
    ///\brief predecessor[i] will hold predecessor of each node.
    int visited[nodes_number + 1];
    ///\brief visited[i] marks if the node is visited(1) or not(0).
    int count;
    ///\brief count gives the number of nodes seen so far.

    int mindistance, nextnode, i;

    ///\brief Initialize predecessor[], distance[] and visited[].
    for(i = 1; i <= nodes_number; i++){
        distance[i] = matrix[start_node][i];
        predecessor[i] = start_node;
        visited[i] = 0;
    }

    distance[start_node] = 0;
    visited[start_node] = 1;
    count = 1;

    while(count < nodes_number){
        mindistance = INFINITY;

        ///\brief nextnode gives the node at minimum distance.
        for(i = 1; i <= nodes_number; i++){
            if(distance[i] < mindistance && !visited[i]){
                mindistance = distance[i];
                nextnode = i;
            }
        }
        // Check if a better path exists through nextnode.
        visited[nextnode] = 1;
        for(i = 1; i <= nodes_number; i++){
            if(!visited[i]){
                if(mindistance + matrix[nextnode][i] < distance[i]){
                    distance[i] = mindistance + matrix[nextnode][i];
                    predecessor[i] = nextnode;
                }
            }
        }
        count++;
    }
    print_path(matrix, nodes_number, start_node, end_node,distance, predecessor);
}
