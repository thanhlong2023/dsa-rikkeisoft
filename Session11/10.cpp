#include <stdio.h>
#include <stdlib.h>

// Cấu trúc node danh sách liên kết đôi
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Tạo node mới
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

// ✅ Hàm đổi chỗ từng cặp node liền kề
Node *swapAdjacentPairs(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *curr = head;
    Node *newHead = head->next; // Sau khi swap lần đầu, node thứ 2 sẽ là head

    while (curr != NULL && curr->next != NULL)
    {
        Node *first = curr;
        Node *second = curr->next;

        // Cập nhật các con trỏ prev/next để đổi chỗ
        Node *prev = first->prev;
        Node *next = second->next;

        if (prev)
            prev->next = second;
        second->prev = prev;

        second->next = first;
        first->prev = second;

        first->next = next;
        if (next)
            next->prev = first;

        // Di chuyển tới cặp kế tiếp
        curr = first->next;
    }

    return newHead;
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

    // Đổi chỗ từng cặp
    head = swapAdjacentPairs(head);

    printf("Danh sach sau khi doi cap:\n");
    printList(head);

    return 0;
}
