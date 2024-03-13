#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("ERROR ALLOCATING MEMMORY");
		exit(1);
	}
	newNode->value = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int findKth(

int main()
{


	return 0;
}
