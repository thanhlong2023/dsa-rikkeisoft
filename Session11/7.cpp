#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}
Node *insertAtPosition(Node *head, int value, int position)
{
    Node *newNode = createNode(value);

    // Trường hợp chèn vào đầu danh sách
    if (position == 0)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode; // new head
    }

    Node *temp = head;
    int i = 0;

    // Duyệt đến vị trí trước vị trí cần chèn
    while (temp != NULL && i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    if (temp == NULL)
    {
        printf("Vị trí vượt quá độ dài danh sách. Không chèn được.\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;

    return head;
}
int main()
{
    // Tạo danh sách ban đầu: 1<->2<->3<->4<->5
    Node *head = createNode(1);
    Node *node2 = createNode(2);
    Node *node3 = createNode(3);
    Node *node4 = createNode(4);
    Node *node5 = createNode(5);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printf("Danh sách ban đầu:\n");
    printList(head);

    int value, position;
    printf("\nNhập giá trị muốn chèn: ");
    scanf("%d", &value);
    printf("Nhập vị trí muốn chèn (0 là đầu): ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    printf("\nDanh sách sau khi chèn:\n");
    printList(head);

    return 0;
}
