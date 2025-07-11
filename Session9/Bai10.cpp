#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("->");
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *swapPairs(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *newHead = head->next;

    while (curr != NULL && curr->next != NULL)
    {
        Node *nextPair = curr->next->next;
        Node *second = curr->next;

        second->next = curr;
        curr->next = nextPair;
        if (prev != NULL)
            prev->next = second;
        prev = curr;
        curr = nextPair;
    }
    return newHead;
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

    head = swapPairs(head);

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