#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char c;
    struct Node * next;

} Node;

Node *makeNode(char value)
{
    Node * node = (Node *) malloc(sizeof(Node));
    node -> c = value;
    node -> next = NULL;
    return node;
}

Node *push(Node *S, char c) {
    Node *newNode = makeNode(c);
    if (S == NULL) {
        return newNode;
    }
    newNode->next = S;     // Link the new node with the stack
    return newNode;
}

Node *pop(Node *S) {
    if (S == NULL) {
        return S;
    }
    else {
        Node *p = S;
        S = S -> next;
        free(p);
        return(S);
    }
}

char top(Node *S){
    if (S == NULL) {
        return '\0';
    }
    return S -> c;
}

bool isEmpty(Node *S)
{
    return (S == NULL);
}
bool match(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
int main(void)
{
    Node *S = NULL;
    char parentheses[100];
    scanf("%s", parentheses);
    int n = strlen(parentheses);

    for (int i = 0; i < n; i++)
        if (parentheses[i] == '(' || parentheses[i] == '{' || parentheses[i] == '['){
            S = push(S, parentheses[i]);
        }

        else if (parentheses[i] == ')' || parentheses[i] == '}' || parentheses[i] == ']') {
            if (isEmpty(S) || !match(top(S), parentheses[i])) {
                printf("false\n");
                return 0;
            }
            S = pop(S);  // Pop the matching opening bracket from the stack
        }

    if (isEmpty(S)) {
        printf("true\n"); // Balanced
    }
    else {
        printf("false\n");
    }

    return 0;
}
