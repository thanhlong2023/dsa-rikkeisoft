#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node Node;
Node *makeNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void pushFront(Node **head, int value)
{
    Node *newNode = makeNode(value);
    newNode->next = *head;
    *head = newNode;
}
void popFront(Node **head)
{
    if (*head == NULL)
        return;
    Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void traverse(Node *head)
{
    if (head == NULL)
    {
        printf("Empty\n");
        return;
    }
    while (head != NULL)
    {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

int main()
{
    Node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        char c[100];
        scanf("%s", c);
        if (strcmp(c, "push") == 0)
        {
            int x;
            scanf("%d", &x);
            pushFront(&head, x);
        }
        else if (strcmp(c, "pop") == 0)
        {
            popFront(&head);
        }
        else
        {
            traverse(head);
        }
    }

       // giả phóng bộ nhớ
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}