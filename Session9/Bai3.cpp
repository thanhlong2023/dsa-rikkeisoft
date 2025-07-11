#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Khong du bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("->");
        current = current->next;
    }
    printf("->NULL\n");
}

int searchList(Node *head, int x)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == x)
            return 1;
        current = current->next;
    }
    return 0;
}

int main()
{
    // Tạo danh sách liên kết đơn với 5 phần tử: 1->2->3->4->5->NULL
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printList(head);

    int x;
    scanf("%d", &x);

    if (searchList(head, x))
        printf("True\n");
    else
        printf("False\n");

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