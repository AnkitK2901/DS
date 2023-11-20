#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int id;
    struct node *next;
}Node;
typedef struct graph
{
    int num_nodes;
    Node**nodes;
}Graph;
Graph*create_graph(int num_nodes)
{
    Graph*graph=(Graph*)malloc(sizeof(Graph));
    graph->num_nodes=num_nodes;
    graph->nodes=(Node**)malloc(num_nodes*sizeof(Node*));
    for(int i=0;i<num_nodes;i++)
    {
        graph->nodes[i]=NULL;
    }
    return graph;
}
void add_edge(Graph*graph,int From,int to)
{
    Node*new_node=(Node*)malloc(sizeof(Node));
    new_node->id=to;
    new_node->next=graph->nodes[From];
    graph->nodes[From]=new_node;
}
void print_graph(Graph*graph)
{
    for(int i=0;i<graph->num_nodes;i++)
    {
        Node*node=graph->nodes[i];
        printf("%d:",i);
        while(node!=NULL)
        {
            printf("%d",node->id);
            node=node->next;
        }
        printf("\n");
    }
}
int main()
{
    Graph*graph=create_graph(7);
    add_edge(graph,0,1);
    add_edge(graph,1,0);
    add_edge(graph,1,2);
    add_edge(graph,2,1);
    add_edge(graph,2,3);
    add_edge(graph,3,2);
    add_edge(graph,3,4);
    add_edge(graph,4,3);
    add_edge(graph,4,5);
    add_edge(graph,5,4);
    add_edge(graph,5,6);
    add_edge(graph,6,5);
    print_graph(graph);
    return 0;
}