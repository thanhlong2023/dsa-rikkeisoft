#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;     // Mảng chứa phần tử
    int front;    // Chỉ số đầu
    int rear;     // Chỉ số cuối
    int capacity; // Sức chứa tối đa
} Queue;

Queue createQueue(int maxSize)
{
    Queue q;
    q.arr = (int *)malloc(sizeof(int) * maxSize);
    q.front = 0;
    q.rear = -1;
    q.capacity = maxSize;
    return q;
}
void enqueue(Queue *q, int value)
{
    if (q->rear == q->capacity - 1)
    {
        printf("queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = value;
}
void printQueue(Queue q)
{
    printf("queue = {\n");
    printf("   array = [");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d", q.arr[i]);
        if (i < q.rear)
            printf(", ");
    }
    printf("],\n");
    printf("   front = %d,\n", q.front);
    printf("   rear = %d,\n", q.rear);
    printf("   capacity = %d\n", q.capacity);
    printf("}\n");
}

int main()
{
    Queue q = createQueue(5);

    printQueue(q); // ban đầu

    int values[] = {3, 1, 2, 5, 3}; // nhập vào 5 số
    for (int i = 0; i < 5; i++)
    {
        enqueue(&q, values[i]);
        printQueue(q);
    }

    // thử thêm nữa khi đầy
    enqueue(&q, 9); // sẽ thông báo đầy

    free(q.arr); // giải phóng bộ nhớ
    return 0;
}
