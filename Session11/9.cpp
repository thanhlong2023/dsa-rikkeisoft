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
        return newNode;

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// In danh sách
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

// ✅ Hàm đảo ngược danh sách liên kết đôi
Node *reverseList(Node *head)
{
    Node *current = head;
    Node *temp = NULL;

    // Duyệt từng node và hoán đổi prev <-> next
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Tiến về "node kế tiếp" sau khi đảo
    }

    // Nếu danh sách không rỗng, cập nhật lại head
    if (temp != NULL)
        head = temp->prev;

    return head;
}

// Main
int main()
{
    Node *head = NULL;

    // Tạo danh sách 1<->2<->3<->4<->5->NULL
    for (int i = 1; i <= 5; i++)
        head = append(head, i);

    printf("Danh sach ban dau:\n");
    printList(head);

    // Đảo ngược
    head = reverseList(head);

    printf("Danh sach sau khi dao nguoc:\n");
    printList(head);

    return 0;
}
