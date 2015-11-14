#include "q.h"

void BFS(Graph_p graph, int src)
{
	int extractQ, i;
	// Add src to the queue
	insertQ(&head, src);
	graph->array[src].explored = 1;
	printf("Breadth First Search Traversal \n");
	while(!isEmpty(&head)) //check if queue is empty
	{
		extractQ = deleteQ(&head);
		printf("%d ", extractQ);
		AdjListNode_p curNode = graph->array[extractQ].head;
		// Add all nodes reachable from curNode to Queue
		while(curNode != NULL)
		{
			if(graph->array[curNode->data].explored == 0)
			{
				graph->array[curNode->data].explored = 1;
				insertQ(&head, curNode->data); 
			}
			curNode = curNode->next;
		}
	}
	printf("\n");
}
