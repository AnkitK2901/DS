#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct graph {
    int num_nodes;
    node **nodes;
} graph;

node* new_node(int data) {
    node* new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

graph* new_graph(int num_nodes) {
    graph* new_graph = malloc(sizeof(graph));
    new_graph->num_nodes = num_nodes;
    new_graph->nodes = malloc(sizeof(node*) * num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        new_graph->nodes[i] = NULL;
    }
    return new_graph;
}

void add_edge(graph* graph, node* src, node* dst) {
    node* new_edge = new_node(dst->data);
    new_edge->next = src->next;
    src->next = new_edge;
}

void print_graph(graph* graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
        node* current = graph->nodes[i];
        printf("%d:", i);
        while (current != NULL) {
            printf("%d->", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    graph* graph_instance = new_graph(8);

    // Initializing nodes
    for (int i = 0; i < 8; i++) {
        graph_instance->nodes[i] = new_node(i);
    }

    add_edge(graph_instance, graph_instance->nodes[0], graph_instance->nodes[1]);
    add_edge(graph_instance, graph_instance->nodes[0], graph_instance->nodes[2]);
    add_edge(graph_instance, graph_instance->nodes[1], graph_instance->nodes[3]);
    add_edge(graph_instance, graph_instance->nodes[1], graph_instance->nodes[4]);
    add_edge(graph_instance, graph_instance->nodes[2], graph_instance->nodes[5]);
    add_edge(graph_instance, graph_instance->nodes[2], graph_instance->nodes[6]);
    add_edge(graph_instance, graph_instance->nodes[3], graph_instance->nodes[5]);
    add_edge(graph_instance, graph_instance->nodes[3], graph_instance->nodes[7]);
    add_edge(graph_instance, graph_instance->nodes[4], graph_instance->nodes[6]);
    add_edge(graph_instance, graph_instance->nodes[4], graph_instance->nodes[7]);

    print_graph(graph_instance);

    return 0;
}
