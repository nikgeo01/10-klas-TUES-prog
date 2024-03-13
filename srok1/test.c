#include <stdio.h>

struct Node{
	int value;
	struct Node* next;
	struct Node* prev;
}

typedef struct LinkedList{
	struct Node* head
	struct Node* tail
}

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	newNode->value = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void merge(struct Node* left, struct Node* right)
{
	if(left == NULL)
	{
		return right;
	}
	if(right == NULL)
	{
		return left;
	}

	struct Node* combined = (struct Node*)malloc(sizeof(struct Node));

	if(left->value <= right->value)
	{
		combined->value = left->value;
		combined->next = merge(left->next, right);
		combined->next->prev = combined;
	}
	else
	{
		combined->value = right->value;
		combined->next = merge(left, right->next);
		combined->next->prev = combined;
	}
	return combined;

}

int main()
{


	return 0;
}
