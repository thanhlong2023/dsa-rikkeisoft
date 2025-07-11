#include <stdio.h>
#include <stdlib.h>

// struct chứa data, và cấu trúc tự trỏ trỏ tới node tiếp theo
struct node
{
    int data;
    struct node *next; // link
};

typedef struct node NODE;

NODE *makeNode(int x)
{
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void pushFront(NODE **head, int x)
{
    NODE *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}

void pushBack(NODE **head, int x)
{
    NODE *newNode = makeNode(x);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    NODE *tmp = *head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

// duyệt danh sách liên kết
void duyet(NODE *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int size(NODE *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

// insert
void insert(NODE **head, int x, int pos)
{
    int n = size(*head);
    if (pos < 1 || pos > n + 1)
    {
        printf("Vi tri khong hop le\n");
        return;
    }
    if (pos == 1)
    {
        pushFront(head, x);
    }
    else if (pos == n + 1)
    {
        pushBack(head, x);
    }
    else
    {
        NODE *tmp = *head;
        for (int i = 1; i < pos; i++)
        {
            tmp = tmp->next;
        }
        NODE *newNode = makeNode(x);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

// delete
void xoaDau(NODE **head)
{
    if (*head == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }
    NODE *tmp = *head;
    *head = (*head)->next;
    free(tmp);
}

void xoaCuoi(NODE **head)
{
    if (*head == NULL)
    {
        printf("Danh sach rong\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    NODE *tmp = *head;
    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

void xoaViTriBatKi(NODE **head, int pos)
{
    int n = size(*head);
    if (pos < 1 || pos > n)
    {
        printf("Vi tri khong hop le\n");
        return;
    }
    if (pos == 1)
    {
        xoaDau(head);
        return;
    }
    NODE *tmp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        tmp = tmp->next;
    }
    NODE *toDelete = tmp->next;
    tmp->next = toDelete->next;
    free(toDelete);
}

void selectionSort(NODE **head)
{
    for (NODE *i = *head; i != NULL; i = i->next)
    {
        NODE *minNode = i;
        for (NODE *j = i->next; j != NULL; j = j->next)
        {
            if (j->data < minNode->data)
            {
                minNode = j;
            }
        }
        // Hoán đổi giá trị giữa i và minNode
        int tmp = i->data;
        i->data = minNode->data;
        minNode->data = tmp;
    }
}

int main()
{
    NODE *head = NULL;
    while (1)
    {
        printf("1. Them phan tu vao dau danh sach\n");
        printf("2. Them phan tu vao cuoi danh sach\n");
        printf("3. Hien thi danh sach\n");
        printf("4. Them phan tu vao vi tri bat ki\n");
        printf("5. Xoa phan tu o dau danh sach\n");
        printf("6. Xoa phan tu o cuoi danh sach\n");
        printf("7. Xoa phan tu o vi tri bat ki\n");
        printf("8. Sap xep danh sach\n");
        printf("0. Thoat\n");
        int lc;
        printf("Nhap lua chon: ");
        scanf("%d", &lc);
        if (lc == 1)
        {
            printf("Nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            pushFront(&head, x);
        }
        else if (lc == 2)
        {
            printf("Nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            pushBack(&head, x);
        }
        else if (lc == 3)
        {
            printf("Danh sach hien tai: ");
            duyet(head);
            printf("\n");
        }
        else if (lc == 4)
        {
            printf("Nhap gia tri can them: ");
            int x;
            scanf("%d", &x);
            printf("Nhap vi tri can them (1-based): ");
            int pos;
            scanf("%d", &pos);
            insert(&head, x, pos);
        }
        else if (lc == 5)
        {
            xoaDau(&head);
        }
        else if (lc == 6)
        {
            xoaCuoi(&head);
        }
        else if (lc == 7)
        {
            printf("Nhap vi tri can xoa (1-based): ");
            int pos;
            scanf("%d", &pos);
            xoaViTriBatKi(&head, pos);
        }
        else if (lc == 8)
        {
            selectionSort(&head);
        }
        else if (lc == 0)
        {
            break;
        }
        else
        {
            printf("Lua chon khong hop le!\n");
        }
    }
    // Giai phong bo nho
    while (head != NULL)
    {
        xoaDau(&head);
    }
    return 0;
}
