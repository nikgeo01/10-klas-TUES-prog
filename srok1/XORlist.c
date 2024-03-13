#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* pointer;
};


struct Node *xorpointer(struct Node *a, struct Node *b)
{
	return (struct Node*)((size_t)a ^ (size_t)b);
}

struct Node *createNode(struct Node** head, int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->pointer = NULL;
	return newNode;
}

struct Node* pushFront(struct Node **head, int value)
{
	struct Node * newNode = createNode(head, value);
	newNode->pointer = xor(*head, (*head)->pointer);
	head->pointer = xorpointer(head, newNode);
	return newNode;
}


int popFront(struct Node* head)
{
	if(*head == NULL)
	{
		printf("Empty list!\n");
		return;
	}
	struct Node* curr = xorpointer(head->pointer, NULL);
	int result = curr->value;
	struct Node* next = xorpointer(head, curr->pointer);
	head->pointer = next;
	next->pointer = xorpointer(head, xorpointer(curr, next->pointer));
	free(curr);

	return result;
}

void printList(struct Node *curr)
{
	struct Node *prev = NULL;
	while(curr)
	{
		printf("%d ", curr->value);
		struct Node *temp = curr;
		curr =  xorpointer(temp->pointer, prev);
		prev = temp;
		free(temp);
	}
	printf("\n");
}

int containsRec(struct Node* prev, struct Node *curr, int value)
{
	if (xorpointer(prev, curr->pointer) == NULL)
	{
		return 0;
	}
	return (curr->value == value) || containsRec(curr, xorpointer(prev, curr->pointer), value);
}

int  containsIter(struct Node *curr, int value)
{
	struct Node* prev = NULL;
	if(curr->pointer == NULL)
	{
		return 0;
	{
	while(xorpointer(prev, curr->pointer) != NULL)
	{
		if(curr->value == value)
		{
			return 1;
		}
		struct Node* temp = curr;
		curr = xorpointer(prev, curr->pointer);
		prev = temp;
		free(temp);
	}
	return 0;
}


int main()
{
	struct Node* head = NULL;
	head = pushFront(head, 33);
	head = pushFront(head, 69);
	head = pushFront(head, 420);
	head = pushFront(head, 343);
	printList(head);
	return 0;
}
