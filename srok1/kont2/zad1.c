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

int is_branch(struct Node* cur)
{

	if(cur == NULL) return 1;
	if(cur->left != NULL && cur->right != NULL) return 0;
	if(cur->left == NULL && cur->right == NULL) return 1;
	return is_branch(cur->left) && is_branch(cur->right);

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

	printf("%d\n", is_branch(TreeRoot));

	return 0;
}
