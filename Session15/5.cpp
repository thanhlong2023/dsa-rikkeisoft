#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct
{
    int array[MAX_SIZE];
    int front;
    int rear;
    int capacity;
} Queue;

bool isEmpty(Queue q)
{
    return q.front > q.rear;
}
int dequeue(Queue *q)
{
    if (isEmpty(*q))
    {
        printf("queue is empty\n");
        return -1; // Giá trị đặc biệt báo lỗi
    }

    int value = q->array[q->front];
    q->front++; // Tăng chỉ số front
    return value;
}
int main()
{
    // Hàng đợi rỗng
    Queue q1 = {{}, 0, -1, 5};
    dequeue(&q1); // In: queue is empty

    // Hàng đợi có phần tử
    Queue q2 = {{1, 2, 5}, 0, 2, 5};

    int val = dequeue(&q2);
    printf("return value = %d;\n", val);

    // In trạng thái hàng đợi sau khi lấy ra
    printf("queue = {\n");
    printf("   array = [");
    for (int i = 0; i <= q2.rear; i++)
    {
        printf("%d", q2.array[i]);
        if (i < q2.rear)
            printf(", ");
    }
    printf("],\n   front = %d,\n   rear = %d,\n   capacity = %d\n}\n",
           q2.front, q2.rear, q2.capacity);

    return 0;
}
