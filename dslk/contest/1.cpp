#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char msv[100];
    char hoTen[100];
    double gpa;
    struct Node *next;
};

typedef struct Node Node;
Node *makeNode()
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    getchar();
    gets(newNode->msv);
    gets(newNode->hoTen);
    scanf("%lf", &newNode->gpa);
    newNode->next = NULL;
    return newNode;
}
void pushFront(Node **head)
{
    Node *newNode = makeNode();
    newNode->next = *head;
    *head = newNode;
}
void pushBack(Node **head)
{
    Node *newNode = makeNode();
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
void insert(Node **head, int k)
{
    if (k == 1)
        pushFront(head);
    else if (k == size(*head) + 1)
        pushBack(head);
    else
    {
        Node *temp = *head;
        for (int i = 1; i < k - 1; i++)
        {
            temp = temp->next;
        }
        Node *newNode = makeNode();
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void travelse(Node *head)
{
    while (head != NULL)
    {
        printf("%s %s %.2lf\n", head->msv, head->hoTen, head->gpa);
        head = head->next;
    }
}
int main()
{
    Node *head = NULL;
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int tt;
        scanf("%d", &tt);
        if (tt == 1)
        {
            pushFront(&head);
        }
        else if (tt = 2)
        {
            pushBack(&head);
        }
        else
        {
            int k;
            scanf("%d", &k);
            insert(&head, k);
        }
    }
    travelse(head);
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