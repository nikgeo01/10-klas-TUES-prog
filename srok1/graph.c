#include <stdio.h>
#include <stdlib.h>

typedef struct Edge{
    struct Node* dest;
    int weight;
}Edge;

typedef struct Node{
    int value;
    Edge* edges;
    int numEdges;
}Node;

typedef struct Graph {
    Node** nodes;
    int numNodes;
} Graph;

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode)
    {
        newNode->value = value;
        newNode->edges = NULL;
        newNode->numEdges = 0;
    }
    return newNode;
}

void addEdge(Node* source, Node* dest) {
    if (source == NULL || dest == NULL) return;

    source->edges = (Edge*)realloc(source->edges, (source->numEdges + 1) * sizeof(Edge));
    if (source->edges)
    {
        Edge newEdge;
        newEdge.dest = dest;
        source->edges[source->numEdges] = newEdge;
        source->numEdges++;
    }
}

void addNode(Graph* graph, Node* newNode) {
    if (graph == NULL || newNode == NULL) return;

    graph->nodes = (Node**)realloc(graph->nodes, (graph->numNodes + 1) * sizeof(Node*));
    if (graph->nodes)
    {
        graph->nodes[graph->numNodes] = newNode;
        graph->numNodes++;
    }
}

void printNode(Node* node, Node *arr, int num)
{
    
    for (int i = 0; i < num; i++)
    {
	if (node == arr[i])
	{
	    return;
	}
    }
	

void print(Graph* graph)
{
    Node arr[graph->numNodes - 1];
    for (int i = 0; i < graph->numNodes; i++)
    {
	arr[i] = NULL;
    }
    

}

int main() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph)
    {
        graph->nodes = NULL;
        graph->numNodes = 0;

        Node* node1 = createNode(1);
        Node* node2 = createNode(2);
        Node* node3 = createNode(3);
        Node* node4 = createNode(4);
        Node* node5 = createNode(5);
        Node* node6 = createNode(6);

        addNode(graph, node1);
        addNode(graph, node2);
        addNode(graph, node3);
        addNode(graph, node4);
        addNode(graph, node5);
        addNode(graph, node6);

        addEdge(node1, node2);
        addEdge(node2, node1);
        addEdge(node1, node3);
        addEdge(node3, node1);
        addEdge(node1, node4);
        addEdge(node2, node5);
        addEdge(node5, node2);
        addEdge(node3, node5);
        addEdge(node5, node3);
        addEdge(node4, node6);
        addEdge(node6, node4);
        addEdge(node5, node6);
        addEdge(node6, node5);
    }


    for (int i = 0; i < graph->numNodes; i++)
    {
        free(graph->nodes[i]->edges);
        free(graph->nodes[i]);
    }

    free(graph->nodes);
    free(graph);

    return 0;
}

