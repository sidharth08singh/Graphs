#include<stdio.h>
#include<stdlib.h>

// A structure to represent an adjacency list node
typedef struct AdjListNode 
{
	int data;
	struct AdjListNode* next;
} AdjListNode_t , *AdjListNode_p;

// A structure to represent an adjacency list
typedef struct AdjList
{
	struct AdjListNode *head;
} AdjList_t, *AdjList_p;

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of a graph is V (number of vertices in the graph) 
typedef struct Graph
{
	int v;
	struct AdjList* array;
} Graph_t, *Graph_p;

// A utility function to create a new adjacency list node
AdjListNode_p newAdjListNode(int data)
{
	AdjListNode_p newnode = (AdjListNode_p)malloc(sizeof(AdjListNode_t));
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}


// A utility function that creates a graph of V vertices
Graph_p createGraph(int V)
{
	Graph_p graph = (Graph_p)malloc(sizeof(Graph_t));
	graph->v = V;
	graph->array = (AdjList_p)malloc(V * sizeof(AdjList_t));
	int i; 
	for(i = 0; i < V; i++)
	{
		graph->array[i].head = NULL;
	}
	return graph;
}

// A utility function to add an edge to an undirected graph
void addEdgeUndirected(Graph_p graph, int src, int dest)
{
	// Add an edge from src to dest. A new node is added to the adjacency list of the src. 
	// New Node added to front of the adjacency list. 
	AdjListNode_p newNode = newAdjListNode(dest);
	newNode->next = graph->array[src].head;
	graph->array[src].head = newNode;

	// Add an edge from dest to src
	newNode = newAdjListNode(src);
	newNode->next = graph->array[dest].head;
	graph->array[dest].head = newNode;
}

void printGraph(Graph_p graph)
{
	int i;
	for(i = 0 ; i < graph->v; i++)
	{
		AdjListNode_p newNode = graph->array[i].head;
		printf("\n Adjacency List of Vertex %d : head ", i);
		while(newNode)
		{
			printf(" -> %d", newNode->data);
			newNode = newNode->next;
		}
		printf("\n");
	}
}


// Driver Function to test the functions
int main()
{
	int V = 5; 
	Graph_p graph = createGraph(V);
	addEdgeUndirected(graph, 0, 1);
	addEdgeUndirected(graph, 0, 4);
	addEdgeUndirected(graph, 1, 2);
	addEdgeUndirected(graph, 1, 3);
	addEdgeUndirected(graph, 1, 4);
	addEdgeUndirected(graph, 2, 3);
	addEdgeUndirected(graph, 3, 4);

	//Print the Adjacency List
	printGraph(graph);
	return 1;
}
