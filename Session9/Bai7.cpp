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

// Hàm thêm một node có giá trị 'value' vào vị trí 'pos' trong danh sách liên kết đơn
Node *addAtPosition(Node *head, int value, int pos)
{
    // Nếu vị trí cần chèn <= 1, thì chèn node mới vào đầu danh sách
    if (pos <= 1)
    {
        Node *newNode = createNode(value); // Tạo node mới
        newNode->next = head;              // Trỏ node mới vào head hiện tại
        return newNode;                    // Trả về node mới làm head mới
    }

    Node *temp = head; // Dùng để duyệt danh sách
    int count = 1;     // Biến đếm vị trí hiện tại

    // Duyệt đến node ở vị trí (pos - 1) để chèn node mới sau nó
    while (temp != NULL && count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    Node *newNode = createNode(value); // Tạo node mới

    if (temp == NULL)
    {
        // Nếu không tìm được vị trí hợp lệ (vị trí lớn hơn chiều dài danh sách)
        // thì không chèn được, giải phóng node mới rồi trả về danh sách ban đầu
        free(newNode);
        return head;
    }

    // Chèn node mới vào sau node temp
    newNode->next = temp->next;
    temp->next = newNode;

    return head; // Trả về danh sách sau khi đã chèn
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

    int value, pos;
    printf("value: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &pos);

    head = addAtPosition(head, value, pos);

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