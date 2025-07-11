#include <stdio.h>
#include <stdlib.h>

// Cấu trúc cho một phần tử trong danh sách liên kết đơn
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm tạo phần tử mới
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

// Hàm in danh sách liên kết
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
    printf("->NULL\n");
}

// Hàm xóa phần tử đầu tiên trong danh sách liên kết
Node *removeFirst(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
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

    head = removeFirst(head);

    printList(head);

    // Giải phóng bộ nhớ còn lại
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}