#include<stdlib.h>
#include<stdio.h>

// Implementing Queue using a Single Linked List 

typedef struct QNode
{
	int element;
	struct QNode* next;
} QNode_t, *QNode_p;

QNode_p head;

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

// Print the Nodes of the Queue
void print(QNode_p *head)
{
	printf("Reached Here\n");
	if(*head == NULL)
	{
		printf("Queue Empty\n");
	}
	else
	{		
		QNode_p temp = *head;
		printf("Reached Here\n");
		while(temp != NULL)
		{
			printf("%d ", temp->element);
			temp = temp->next;
		}	
		printf("\n");
	}
}

int main()
{
	head = NULL;
	int ch;
	while(1)
	{
		printf("1. Insert\n2. Delete\n3. Print\n4. Exit\n");
		scanf("%d - ", &ch);
		switch(ch)
		{
			case 1: 
			{
				int val;
				printf("Value : ");
				scanf("%d", &val);
				insertQ(&head, val);
				break;
			}	

			case 2: 
			{
				printf("In case 2\n");
				deleteQ(&head);
				break;
			}
			
			case 3: 
			{
				printf("In case 3\n");
				print(&head);
				break;
			}

			default:
			{
				if(ch == 4)
					exit(1);
				else
					printf("Pick Again!\n");
			}
		}
	}
}
	
	

