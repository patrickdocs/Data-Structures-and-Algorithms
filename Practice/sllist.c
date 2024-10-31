#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int v;
    struct Node * next;

} Node;

Node* find(int k, Node *head){
    Node *p = head;
    while (p != NULL) {
        if (p -> v == k){
            printf("Found\n");
            return p;
        }
        p = p -> next;
    }
    printf("Not Found\n");
    return NULL;
}

Node * makeNode(int value)
{
    Node * node = (Node *) malloc(sizeof(Node));
    node -> v = value;
    node -> next = NULL;
    return node;
}

Node *insertLast(Node * head, int v){
    Node *newNode = makeNode(v);
    if (head == NULL) return newNode;
    Node *p = head;
    while (p -> next != NULL)
    {
        p = p -> next;
    }
    p -> next = newNode;
    return head;
}

Node *findPrev(Node *head, Node *p) {
    if (head == NULL || head == p) {
        return NULL;  // If p is the head or head is NULL, there is no previous node
    }
    Node *prev = head;
    while (prev->next != NULL && prev->next != p) {
        prev = prev->next;
    }
    return prev;
}

Node *insertBeforeNode(Node *head, Node *p, int v) {
    // If the list is empty or p is NULL, return the head unchanged
    if (head == NULL || p == NULL) {
        return head;
    }

    // Find the previous node of p
    Node *prev = findPrev(head, p);

    // Create the new node to insert
    Node *newNode = makeNode(v);

    // If p is the head of the list, update head to point to the new node
    if (prev == NULL) {
        newNode->next = head;
        return newNode;  // New head of the list
    }

    // Insert the new node before p
    newNode->next = p;
    prev->next = newNode;
    return head;
}

void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d -> ", p->v);  // Print the value of the current node
        p = p->next;  // Move to the next node
    }
    printf("NULL\n");  // Indicate the end of the list
}

int main(void)
{
    Node *head, *node1, *node2, *node3;
    head = makeNode(10);
    node1 = makeNode(15);
    node2 = makeNode(18);
    node3 = makeNode(20);

    head -> next = node1;
    node1 -> next = node2;
    node2 -> next = node3;

    Node *result = find(15, head);
    head = insertLast(head, 6);
    printList(head);

    head = insertBeforeNode(head, head -> next, 12);
    printList(head);
    return 0;
}
