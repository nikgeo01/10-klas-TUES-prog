#include <stdio.h>
#include <stdlib.h>

struct Edge
{
    int weight;
    struct Node *node;
};

struct Node
{
    int value;
    struct Edge *edges;
    size_t e_size;
    int side;
};

struct Node *createNode(int value)
{
    struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
    temp->value = value;
    temp->e_size = 0;
    temp->side = 0;
    return temp;
}

struct dNode
{
	size_t len;
	int isVis;
	struct dNode *prev;
}

struct dNode* creatDNode(size_t len)
{
	struct dNode *temp = (struct Node *)calloc(1, sizeof(struct dNode));
	temp->len = len;
	temp->visited = 0;
	temp->prev = NULL;
	

#define V_SIZE 10

int isVisited(struct Node *visited[], struct Node *node)
{
    int i;
    for (i = 0; i < V_SIZE; i++)
    {
        if (visited[i] == node)
            return -1;
        if (visited[i] == NULL)
            break;
    }
    return i;
}

struct QNode
{
    struct Node *value;
    struct QNode *next;
};

struct QNode *createQNode(struct Node *visited[], struct Node *node)
{
    int index = isVisited(visited, node);
    if (index != -1)
    {
        visited[index] = node;
        struct QNode *temp = (struct QNode *)calloc(1, sizeof(struct QNode));
        temp->value = node;
        temp->next = NULL;
        return temp;
    }
    else
    {
        return NULL;
    }
}

struct SNode
{
    struct Node *value;
    struct SNode *next;
};

void createBond(struct Node *node1, struct Node *node2, int weight)
{
    if (!node1 || !node2)
        return;
    node1->e_size++;
    node1->edges = (struct Edge *)realloc(node1->edges, node1->e_size * sizeof(struct Edge));
    node2->e_size++;
    node2->edges = (struct Edge *)realloc(node2->edges, node2->e_size * sizeof(struct Edge));
    node1->edges[node1->e_size - 1].node = node2;
    node1->edges[node1->e_size - 1].weight = weight;
    node2->edges[node2->e_size - 1].node = node1;
    node2->edges[node2->e_size - 1].weight = weight;
}

struct Node *push(struct Node *node, int num)
{
    if (!node)
        return createNode(num);
    struct Node *temp = createNode(num);
    createBond(node, temp);
    return temp;
}

void initNodeArr(struct Node *nodes[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        nodes[i] = createNode(i + 1);
    }
}

void printGraph(struct Node *node, struct Node *visited[])
{
    if (!node)
        return;
    int index = isVisited(visited, node);
    if (index == -1)
        return;
    printf("%d ", node->value);
    visited[index] = node;
    for (int i = 0; i < node->e_size; i++)
    {
        printGraph(node->edges[i].node, visited);
    }
}

struct QNode *createQueue(struct Node *visited[], struct Node *node)
{
    if (!node) return NULL;
    struct QNode *head = createQNode(visited, node);
    struct QNode *cur = head, *begining = head;
    if (!head)
        return NULL;
    for (int i = 1;; i++)
    {
        for (int j = 0; j < node->e_size; j++)
        {
            struct QNode *temp = createQNode(visited, node->edges[j].node);
            if (temp)
            {
                head->next = temp;
                head = temp;
            }
        }
        cur = cur->next;
        if (cur == NULL)
            break;
        node = cur->value;
    }
    return begining;
}

void BFS(struct Node *node, struct Node *visited[])
{
    printf("BFS\n");
    struct QNode *head = createQueue(visited, node);
    printf("afterCreateQueue\n");
    while (head)
    {
        printf("%d ", head->value->value);
        head = head->next;
    }
}

void DFS(struct Node *node, struct Node *visited[])
{
    if (!node)
        return;
    int index = isVisited(visited, node);
    if (index == -1)
        return;
    visited[index] = node;
    printf("%d ", node->value);
    for (int i = 0; i < node->e_size; i++)
    {
        DFS(node->edges[i].node, visited);
    }
}

void callAlg(struct Node *node, struct Node *visited[])
{
    printf("1-BFS or 2-DFS\n");
    int num;
    scanf("%d", &num);
    if (num == 1)
    {
        BFS(node, visited);
    }
    else if (num == 2)
    {
        DFS(node, visited);
    }
    else
    {
        printf("Invalid input\n");
    }
}

int isOtherSide(struct Node *node1, struct Node *node2)
{
    if (node1->side == 0 && node2->side == 0)
    {
        node1->side = 1;
        node2->side = 2;
        return 1;
    }
    else if (node1->side == 0)
    {
        if (node2->side == 1)
        {
            node1->side = 2;
            return 1;
        }
        else if (node2->side == 2)
        {
            node1->side = 1;
            return 1;
        }
    }
    else if (node2->side == 0)
    {
        if (node1->side == 1)
        {
            node2->side = 2;
            return 1;
        }
        else if (node1->side == 2)
        {
            node2->side = 1;
            return 1;
        }
    }
    else if (node1->side == node2->side)
    {
        return 0;
    }
    return 1;

}

int isTwoSided(struct Node *node, struct Node *visited[], int sideToPut)
{
    if (!node)
        return 1;
    if (node->side == 0)
    {
        node->side = sideToPut;
    }
    else
    {
        if (node->side != sideToPut)
            return 0;
    }
    int index = isVisited(visited, node);
    if (index != -1)
    {
        visited[index] = node;
        for (int i = 0; i < node->e_size; i++)
        {
            if (!isTwoSided(node->edges[i].node, visited, sideToPut == 1 ? 2 : 1))
                return 0;
        }
    }
    return 1;

    /* if (!node) return 1;
    if (sideToPut == 0)
    {
        node->side = 1;
        for (int i = 0; i < node->e_size; i++)
        {
            if (node->edges[i]->side == 1)
                return 0;
            int index = isVisited(visited, node->edges[i]);
            if (index != -1)
            {
                node->edges[i]->side = 2;
                visited[index] = node->edges[i];
                return isTwoSided(node->edges[i], visited, 2);
            }
        }
    }
    else if (sideToPut == 1)
    {
        if (node->side == 2)
            return 0;
        node->side = 1;
        for (int i = 0; i < node->e_size; i++)
        {
            if (node->edges[i]->side == 1)
                return 0;
            int index = isVisited(visited, node->edges[i]);
            if (index != -1)
            {
                node->edges[i]->side = 2;
                visited[index] = node->edges[i];
                return isTwoSided(node->edges[i], visited, 2);
            }
        }
    }
    else if (sideToPut == 2)
    {
        if (node->side == 1)
            return 0;
        node->side = 2;
        for (int i = 0; i < node->e_size; i++)
        {
            if (node->edges[i]->side == 2)
                return 0;
            int index = isVisited(visited, node->edges[i]);
            if (index != -1)
            {
                node->edges[i]->side = 1;
                visited[index] = node->edges[i];
                return isTwoSided(node->edges[i], visited, 1);
            }
        }
    }
    return 1; */
}

struct dNode* weightPath(struct Node* node, struct Node* visited[])
{
	if (!node)
        return 1;
    if (node->side == 0)
    {
        node->side = sideToPut;
    }
    else
    {
        if (node->side != sideToPut)
            return 0;
    }
    int index = isVisited(visited, node);
    if (index != -1)
    {
        visited[index] = node;
        for (int i = 0; i < node->e_size; i++)
        {
            if (!isTwoSided(node->edges[i].node, visited, sideToPut == 1 ? 2 : 1))
                return 0;
        }
    }
    return 1
}



#define PRINT_BOND(NODE1, NODE2, I1, I2) printf("%d -> %d && %d -> %d \n", NODE1->value, \
                                                NODE1->edges[I1].node->value,            \
                                                NODE2->value,                            \
                                                NODE2->edges[I2].node->value);


        int main()
        {
            struct Node *nodes[10];
            initNodeArr(nodes, 10);


            createBond(nodes[0], nodes[3]);
            createBond(nodes[3], nodes[1]);
            createBond(nodes[1], nodes[4]);
            createBond(nodes[4], nodes[2]);
            createBond(nodes[2], nodes[5]);
            //createBond(nodes[3], nodes[4]);

            /* createBond(nodes[0], nodes[1]);
            createBond(nodes[0], nodes[2]);
            createBond(nodes[0], nodes[3]);
            createBond(nodes[1], nodes[4]);
            createBond(nodes[2], nodes[4]);
            createBond(nodes[3], nodes[5]);
            createBond(nodes[5], nodes[4]); */
            struct Node *visited[V_SIZE] = {0};
            // printGraph(nodes[0], visited);
            printf("\n");

            //callAlg(nodes[0], visited);

            if (isTwoSided(nodes[0], visited, 1))
            {
                printf("Two sided\n");
            }
            else
            {
                printf("Not two sided\n");
            }

            return 0;
        }
