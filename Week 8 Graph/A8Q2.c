#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data; // Change data type to char
    struct node* next;  
} Node;

typedef struct graph {
    int num_vertices;
    Node **adjacency_lists;
} Graph;

Graph* create_graph(int num_vertices) {
    Graph* graph = malloc(sizeof(Graph));
    if(graph == NULL) {
        return NULL;
    }
    graph->num_vertices = num_vertices;
    graph->adjacency_lists = malloc(sizeof(Node*) * num_vertices);
    if(graph->adjacency_lists == NULL) {
        free(graph);
        return NULL;
    }
    for(int i = 0; i < num_vertices; i++) {
        graph->adjacency_lists[i] = NULL;
    }
    return graph;
}

void add_edge(Graph* graph, char src, char dest) {
    if(graph == NULL) {
        return;
    }

    int source = src - 'A'; // Convert char to integer index ('A' = 0, 'B' = 1, ...)
    int destination = dest - 'A';

    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) {
        return;
    }
    new_node->data = dest; // Store destination vertex as char
    new_node->next = graph->adjacency_lists[source];
    graph->adjacency_lists[source] = new_node;
}

void print_graph(Graph* graph) {
    if(graph == NULL) {
        return;
    }
    for(int i = 0; i < graph->num_vertices; i++) {
        printf("Adjacency List of Vertex %c: ", 'A' + i);
        Node* current_node = graph->adjacency_lists[i];
        while (current_node != NULL) {
            printf("%c -> ", current_node->data); // Print character representing the vertex
            current_node = current_node->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int num_vertices = 7;
    Graph* graph = create_graph(num_vertices);
    if(graph == NULL) {
        printf("Failed to create graph\n");
        return 1;
    }

    add_edge(graph, 'A', 'B');
    add_edge(graph, 'A', 'C');
    add_edge(graph, 'C', 'D');
    add_edge(graph, 'C', 'F');
    add_edge(graph, 'F', 'E');
    add_edge(graph, 'F', 'D');
    add_edge(graph, 'F', 'G');
    add_edge(graph, 'G', 'E');
    add_edge(graph, 'E', 'B');
    add_edge(graph, 'E', 'D');

    print_graph(graph);

    return 0;
}
