#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *xor;
};

struct Node* XOR(struct Node *a, struct Node *b) {
    return (struct Node*) ((size_t) (a) ^ (size_t) (b));
}

void pushfront(struct Node **head, int value) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node *));
    newNode->value = value;
    newNode->xor = XOR(*head, NULL);
    if (*head != NULL) {
        struct Node* next = XOR((*head)->xor, NULL);
        (*head)->xor = XOR(newNode, next);
    }
    *head = newNode;
}

void popfront(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot pop.\n");
        return;
    }

    struct Node *next = XOR((*head)->xor, NULL);
    if (next != NULL) {
        next->xor = XOR(*head, XOR(next->xor, NULL));
    }

    free(*head);
    *head = next;
}

void printXORList(struct Node *head) {
    struct Node *next;
    struct Node *prev = NULL;
    while (head != NULL) {
        printf("%d ", head->value);
        next = XOR(prev, head->xor);
        prev = head;
        head = next;
    }
    printf("\n");
}

int containsIter(struct Node *head, int searched) {
    struct Node *next;
    struct Node *prev = NULL;
    while (head != NULL) {
        if (head->value == searched) return 1;
        next = XOR(prev, head->xor);
        prev = head;
        head = next;
    }
    return 0;
}

int containsRec(struct Node *head, int searched, struct Node *prev) {
    if (head == NULL) return 0;
    if (head->value == searched) return 1;
    return containsRec(XOR(prev, head->xor), searched, head);
}

int main() {
    struct Node *head = NULL;
    pushfront(&head, 3);
    pushfront(&head, 4);
    pushfront(&head, 5);
    pushfront(&head, 6);

    printf("Original List: ");
        printXORList(head);

    popfront(&head);
    
    printf("List after popping front: ");
    printXORList(head);

    printf("List contains 5: %d\n", containsIter(head, 5));
    printf("Recursive: %d\n", containsRec(head, 5, NULL));

    return 0;
}
