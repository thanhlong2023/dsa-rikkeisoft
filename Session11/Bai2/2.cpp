#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = NULL;
        return newNode;
    }
}

void printList(Node *head)
{
    Node *current = head;
    int idx = 1;
    while (current != NULL)
    {
        printf("Node %d: %d\n", idx, current->data);
        idx++;
        current = current->next;
    }
}

int main()
{
    Node *head = createNode(1);
    Node *second = createNode(2);
    Node *third = createNode(3);
    Node *fourth = createNode(4);
    Node *fifth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    printList(head);

    // Giải phóng bộ nhớ
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}