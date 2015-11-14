#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
#include "BFS.h"


// Driver Function to test the functions
int main()
{
	int V;
	//Graph 1
	V = 5; 
	graph = createGraph(V);
	addEdgeUndirected(graph, 0, 1);
	addEdgeUndirected(graph, 0, 4);
	addEdgeUndirected(graph, 1, 2);
	addEdgeUndirected(graph, 1, 3);
	addEdgeUndirected(graph, 1, 4);
	addEdgeUndirected(graph, 2, 3);
	addEdgeUndirected(graph, 3, 4);
	//Print the Adjacency List
	printGraph(graph);
	BFS(graph, 0);

	//Graph 2
	V = 10;
	graph = createGraph(V);
	addEdgeUndirected(graph, 0, 1);
	addEdgeUndirected(graph, 0, 2);
	addEdgeUndirected(graph, 1, 3);
	addEdgeUndirected(graph, 1, 4);
	addEdgeUndirected(graph, 2, 5);
	addEdgeUndirected(graph, 2, 6);
	addEdgeUndirected(graph, 3, 4);
	addEdgeUndirected(graph, 3, 7);
	addEdgeUndirected(graph, 4, 7);
	addEdgeUndirected(graph, 5, 8);
	addEdgeUndirected(graph, 5, 6);
	addEdgeUndirected(graph, 6, 8);
	addEdgeUndirected(graph, 7, 9);
	addEdgeUndirected(graph, 8, 9);
	//Print the Adjacency List
	printGraph(graph);
	BFS(graph, 0);

	return 1;
}
