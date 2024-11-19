#include <stdio.h>

typedef struct PQNode{
	int value;
	int priority;
	struct PQNode* next;
}PriorityQueueNode;

PriorityQueueNode* initQueueNode(int value, int priority){
	PriorityQueueNode* node = malloc(sizeof(PriorityQueueNode));
	node->value = value;
	node->priority = priority;
	node->next = (NULL);
	return node;
}

PriorityQueueNode* pushQueueNode(PriorityQueueNode* node1, PriorityQueueNode* node2){
	if(!node1 || !node2) return (NULL);
	if(node1->priority > node2->priority) return node1->next = node2;
	return pushQueueNode(node1->next, node2);
}

PriorityQueueNode* popQueueNode(PriorityQueueNode* queue){
	if(!queue) return (NULL);
	PriorityQueueNode* temp;
	temp = queue;
	queue = queue->next;
	free(temp);
	return queue;
}

int main(){
	PriorityQueueNode* node1 = initQueueNode(5,3);
	PriorityQueueNode* node2 = initQueueNode(4,2);
	node1
}
