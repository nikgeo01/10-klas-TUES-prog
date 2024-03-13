#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

void storeBSTNodes(struct Node* root, struct Node** nodes, int* index) {
    if (root == NULL)
        return;

    storeBSTNodes(root->left, nodes, index);
    nodes[(*index)++] = root;
    storeBSTNodes(root->right, nodes, index);
}

struct Node* buildTreeUtil(struct Node** nodes, int start, int end) {
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    struct Node* root = nodes[mid];

    root->right = buildTreeUtil(nodes, start, mid - 1);
    root->left = buildTreeUtil(nodes, mid + 1, end);

    return root;
}

struct Node* buildTree(struct Node* root) {
    if (root == NULL)
        return NULL;

    int n = 0;
    struct Node* nodes[100];  
    storeBSTNodes(root, nodes, &n);

    return buildTreeUtil(nodes, 0, n - 1);
}

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node != NULL) {
        node->data = data;
        node->left = node->right = NULL;
    }
    return node;
}

void preOrder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(3);
    root->left->left->left = newNode(4);

    root = buildTree(root);

    printf("Preorder traversal of balanced BST is : \n");
    preOrder(root);

    return 0;
}
