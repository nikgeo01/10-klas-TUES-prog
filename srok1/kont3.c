#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value
	struct Node* next;
	struct Node* prev;
	struct Node* snext;
	struct Node* sprev;
}

typedef struct LinkedList{
	struct Node* head;
}LinkedList;

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*) malloc (sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("ERROR ALLOCARING!");
		exit(1);
	}
	newNode->value = valur;
	newNode->next = NULL;
	newNode->prev = NULL;
	newNode->snext = NULL;
	newNode->sprev = NULL;

	return newNode;
}

void pushFront(struct Node* head, int value)
{
	struct Node* node = createnode(value);

	if(head == NULL)
	{
		head = node;
		return;
	}
	node->next = head->next;
	node->prev = head;
	node->next->prev = node;

	


int main()
{


	return 0;
}
