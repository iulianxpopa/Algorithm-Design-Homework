#define INFINITY 99999

void print_matrix(int **matrix, int nodes_number);
void path(int **roy_floyd_matrix, int nodes_number, int start_node, int end_node);
void show_path(int **roy_floyd_matrix, int nodes_number, int start_node, int end_node, int **matrix);
