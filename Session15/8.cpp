#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct
{
    char name[50];
    int age;
} Customer;

typedef struct
{
    Customer data[MAX];
    int front;
    int rear;
} Queue;

// Khởi tạo queue
void initQueue(Queue *q)
{
    q->front = q->rear = -1;
}

// Kiểm tra queue rỗng
int isEmpty(Queue *q)
{
    return q->front == -1;
}

// Kiểm tra queue đầy
int isFull(Queue *q)
{
    return (q->rear + 1) % MAX == q->front;
}

// Thêm khách vào queue
void enqueue(Queue *q, Customer c)
{
    if (isFull(q))
    {
        printf("Queue is full!\n");
        return;
    }

    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX;
    }

    q->data[q->rear] = c;
}

// Lấy khách ra khỏi queue
Customer dequeue(Queue *q)
{
    Customer c = {"", -1};
    if (isEmpty(q))
    {
        printf("Queue is empty!\n");
        return c;
    }

    c = q->data[q->front];
    if (q->front == q->rear)
    {
        // Xóa phần tử cuối cùng
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % MAX;
    }

    return c;
}

// In thông tin khách hàng
void printCustomer(Customer c)
{
    if (c.age != -1)
        printf("Phục vụ khách: %s (tuổi %d)\n", c.name, c.age);
}

// Main chương trình
int main()
{
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int n;
    printf("Nhập số lượng khách hàng: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        Customer c;
        printf("Nhập tên khách hàng %d: ", i + 1);
        scanf("%s", c.name);
        printf("Nhập tuổi: ");
        scanf("%d", &c.age);

        if (c.age >= 60)
            enqueue(&queueOld, c);
        else
            enqueue(&queueNormal, c);
    }

    printf("\n--- Bắt đầu phục vụ khách hàng ---\n");
    while (!isEmpty(&queueOld) || !isEmpty(&queueNormal))
    {
        Customer c;

        if (!isEmpty(&queueOld))
            c = dequeue(&queueOld);
        else
            c = dequeue(&queueNormal);

        printCustomer(c);
    }

    return 0;
}
