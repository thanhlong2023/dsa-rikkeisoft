#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node của danh sách liên kết đôi
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Hàm tạo node mới
Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Thêm node vào cuối danh sách
Node *append(Node *head, int value)
{
    Node *newNode = createNode(value);
    if (head == NULL)
    {
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// In danh sách liên kết đôi
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf("<->");
        }
        temp = temp->next;
    }
    printf("->NULL\n");
}

// Xoá phần tử tại vị trí chỉ định
Node *deleteAtPosition(Node *head, int position)
{
    if (head == NULL || position < 0)
    {
        return head;
    }

    Node *temp = head;

    // Nếu xoá node đầu tiên
    if (position == 0)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }

    // Di chuyển đến vị trí cần xoá
    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        return head; // Vị trí không hợp lệ
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return head;
}

// Hàm chính
int main()
{
    Node *head = NULL;

    // Tạo danh sách: 1<->2<->3<->4<->5->NULL
    for (int i = 1; i <= 5; i++)
    {
        head = append(head, i);
    }

    printf("Danh sach ban dau:\n");
    printList(head);

    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);

    head = deleteAtPosition(head, pos);

    printf("Danh sach sau khi xoa:\n");
    printList(head);

    return 0;
}
