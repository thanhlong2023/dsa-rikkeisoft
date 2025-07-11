#include <stdio.h>
#include <stdlib.h>

// Khai báo node
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Tạo node mới
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Thêm node vào cuối danh sách
void append(Node **head, int value)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// In danh sách
void printList(Node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Xoá node tại vị trí
void deleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
        return;

    // Xoá đầu nếu position <= 0
    if (position <= 0)
    {
        Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    int index = 1;

    // Duyệt đến vị trí
    while (current != NULL && index < position)
    {
        prev = current;
        current = current->next;
        index++;
    }

    // Nếu vượt quá cuối danh sách → xoá cuối
    if (current == NULL && prev != NULL)
    {
        current = *head;
        while (current->next && current->next->next != NULL)
            current = current->next;

        Node *temp = current->next;
        current->next = NULL;
        free(temp);
        return;
    }

    // Xoá tại vị trí hợp lệ
    if (prev != NULL && current != NULL)
    {
        prev->next = current->next;
        free(current);
    }
}

// Hàm chính
int main()
{
    Node *head = NULL;

    // Tạo danh sách 1->2->3->4->5->NULL
    for (int i = 1; i <= 5; i++)
    {
        append(&head, i);
    }

    printf("Danh sách ban đầu:\n");
    printList(head);

    int pos;
    printf("Nhập vị trí muốn xoá: ");
    scanf("%d", &pos);

    deleteAtPosition(&head, pos);

    printf("Danh sách sau khi xoá:\n");
    printList(head);

    return 0;
}
