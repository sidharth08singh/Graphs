#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// A structure to represent an adjacency list node
typedef struct AdjListNode 
{
	int data;
	struct AdjListNode* next;
} AdjListNode_t , *AdjListNode_p;

// A structure to represent an adjacency list
typedef struct AdjList
{
	int explored;
	int level;
	struct AdjListNode *head;
} AdjList_t, *AdjList_p;

// A structure to represent a graph. A graph is an array of adjacency lists. 
// Size of a graph is V (number of vertices in the graph) 
typedef struct Graph
{
	int v;
	struct AdjList* array;
} Graph_t, *Graph_p;

Graph_p graph;

typedef struct QNode
{
	int element;
	struct QNode* next;
} QNode_t, *QNode_p;

QNode_p head;

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
		graph->array[i].level = 0;
		graph->array[i].explored = 0;
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

/*
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
*/

QNode_p createNode(int element)
{
	QNode_p newnode = (QNode_p)malloc(sizeof(QNode_t));
	newnode->element = element;
	newnode->next = NULL;
	return newnode;
}

// Insert to the rear of the Queue
void insertQ(QNode_p *head, int element)
{
	QNode_p newnode = createNode(element);
	if(*head == NULL) // Inserting first node
	{
		*head = newnode;
	}
	else
	{
		QNode_p temp = *head;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newnode;
	}
}

// Delete from the front of the Queue
int deleteQ(QNode_p *head)
{
	if(*head == NULL)
	{	
		return -1;  // If Queue is Empty
	}
	QNode_p temp = *head;
	QNode_p temp1 = *head;
	temp = temp->next;
	*head = temp;
	int front;
	front = temp1->element;
	free(temp1);
	return front;
}

// A utility function to check if Queue is empty or not
int isEmpty(QNode_p *head)
{
	if(*head == NULL)
		return 1;
	else
		return 0;
}		

// Print the Nodes of the Queue
/*
void print(QNode_p *head)
{
	if(*head == NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{		
		QNode_p temp = *head;
		while(temp != NULL)
		{
			printf("%d ", temp->element);
			temp = temp->next;
		}	
		printf("\n");
	}
}
*/

void BFS(Graph_p graph, int src)
{
	int extractQ, i;
	// Add src to the queue
	insertQ(&head, src);
	graph->array[src].explored = 1;
	while(!isEmpty(&head)) //check if queue is empty
	{
		extractQ = deleteQ(&head);
		AdjListNode_p curNode = graph->array[extractQ].head;
		// Add all nodes reachable from curNode to Queue
		while(curNode != NULL)
		{
			if(graph->array[curNode->data].explored == 0)
			{
				graph->array[curNode->data].level = graph->array[extractQ].level + 1;
				graph->array[curNode->data].explored = 1;
				insertQ(&head, curNode->data); 
			}
			curNode = curNode->next;
		}
	}

	//printf("\n");
	for(i = 0; i < graph->v; i++)
	{
		if(i != src)
		{
			if(graph->array[i].level != 0)
			{
				printf("%d ", graph->array[i].level * 6);
			}
			else
			{
				printf("-1 ");
			}
		}
	}

	
}


int main() 
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t, v, e, i, from, to, start;
    scanf("%d", &t);
    while(t>0)
    {
        scanf("%d %d", &v, &e);
	Graph_p graph = createGraph(v);
        for(i = 0; i < e; i++)
        {
            scanf("%d %d", &from, &to);
	    addEdgeUndirected(graph, from-1, to-1);
        }
        scanf("%d", &start);
	BFS(graph, start-1);
	printf("\n");
        t--;
    }
    return 0;
}
