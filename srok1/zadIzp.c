#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	int left;
	int right;
	int top;
	int bot;
}

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("Error allocating mammory!");
		exit(1);
	}
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

struct Node* push(struct Node* cur, int value)
{
	if(cur == NULL)
	{
		return createNode(value);
	}

	if(cur->value >= value)
	{
		cur->left = push(cur->left, value);
	}
	else
	{
		if(cur->value < value)
		{
			cur->right = push(cur->right, value);
		}
	}

	return cur;
}

int size (struct Node* node)
{
	if(node == NULL)
	{
		return 0;
	}
	return (1 + size(node->left) + size(node->right));
}


int depth (struct Node* node)
{
	if(node == NULL)
	{
		return 0;
	}
	return (1 + ((depth(node->left) > depth(node->right)) ? depth(node->left):depth(node->right)));
}

void printTree(struct Node* cur)
{
	if(cur == NULL)
	{
		free(cur);
		return;
	}

	printf("%d ", cur->value);
	printTree(cur->left);
	printTree(cur->right);
}

void freeMem(struct Node* cur)
{
	if(cur == NULL)
	{
		return;
	}

	freeMem(cur->left);
	freeMem(cur->right);

	free(cur);
}

int main()
{
	int mat [3][5] =
	{
	{'0', '0', '0', '1', '1'},
	{'1', '0', '0', '0', '0'},
	{'1', '0', '0', '1', '0'}
	};

	struct Node* TreeRoot1 = NULL;
	TreeRoot1 = push(TreeRoot1, 40);
	push(TreeRoot1, 20);
	push(TreeRoot1, 10);
	push(TreeRoot1, 70);
	push(TreeRoot1, 30);
	push(TreeRoot1, 60);

	printTree(TreeRoot1);

	printf("\nSize: %d\n", size(TreeRoot1));
	printf("Is BST: %d\n", isBST(TreeRoot1));
	printf("Depth: %d\n", depth(TreeRoot1));
	printf("Is balanced: %d\n", isBalanced(TreeRoot1));

	struct Node* TreeRoot2 = NULL;
	TreeRoot2 =  push(TreeRoot2, 70);
	push(TreeRoot2, 60);

	printf("Subtree:\n");
	printTree(TreeRoot2);
	printf("\nIs sub tree: %d\n", subTree(TreeRoot1, TreeRoot2, 0));

	printf("\nIs identical: %d\n", isIdentical(TreeRoot1, TreeRoot2));

	freeMem(TreeRoot1);

  return 0;
}
