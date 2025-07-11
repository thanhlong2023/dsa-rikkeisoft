#include <stdio.h>
#include <stdlib.h>

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

void pushBack(Node **head, int value)
{
    Node *newNode = makeNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
int size(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void traverse(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        if (head->next != NULL)
            printf("->");
        else
            printf("->NULL\n");
        head = head->next;
    }
}
void xoa(Node **head, int x)
{
    while ((*head) != NULL && (*head)->data == x)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node *temp = *head;
    Node *prev = temp;
    while (temp != NULL)
    {
        if (temp->data == x)
        {
            prev->next = temp->next;
            free(temp);
            temp = prev->next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
}
int main()
{
    Node *head = NULL;
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int y;
        scanf("%d", &y);
        pushBack(&head, y);
    }
    scanf("%d", &x);
    xoa(&head, x);

    traverse(head);
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