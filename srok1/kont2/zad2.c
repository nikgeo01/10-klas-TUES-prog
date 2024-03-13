#include <stdio.h>
#include <stdlib.h>

struct Node{
	int value;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value)
{
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
	if(newNode == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	newNode->value = value;
	newNode->right = NULL;
	newNode->left = NULL;

	return newNode;
}

int smallest_product_to_leaf(struct Node* cur)
{
	if(cur->left == NULL  && cur->right == NULL) return 1;
	int pr1 = 0;
	int pr2 = 0;

	if(cur->left != NULL && cur->right != NULL)
	{
		int a = smallest_product_to_leaf(cur->left);
		int b = smallest_product_to_leaf(cur->right);
		pr1 = cur->left->value * ((abs(a) <= abs(b)) ? a:b );
	}
	else if(cur->left != NULL)
	{
		pr1 = cur->left->value * smallest_product_to_leaf(cur->left);
	}
	else if(cur->right != NULL)
	{
		pr2 = cur->right->value * smallest_product_to_leaf(cur->right);
	}

	if(abs(pr1) <= abs(pr2))
	{
		return cur->value * pr1;
	}
	else
	{
		return cur->value * pr2;
	}
}

int main()
{

	struct Node* TreeRoot = createNode(5);
	TreeRoot->left = createNode(4);
	TreeRoot->left->left = createNode(11);
	TreeRoot->left->left->left = createNode(7);
	TreeRoot->left->left->right = createNode(2);
	TreeRoot->right = createNode(8);
	TreeRoot->right->left = createNode(13);
	TreeRoot->right->right = createNode(4);
	TreeRoot->right->right->right = createNode(1);

	printf("%d\n", smallest_product_to_leaf(TreeRoot));

	return 0;
}
