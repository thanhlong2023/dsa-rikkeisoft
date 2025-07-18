#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Cấu trúc Queue đơn giản
typedef struct
{
    int *arr;
    int front;
    int rear;
    int size;
} Queue;

Queue createQueue(int capacity)
{
    Queue q;
    q.arr = (int *)malloc(sizeof(int) * capacity);
    q.front = 0;
    q.rear = 0;
    q.size = capacity;
    return q;
}

void enqueue(Queue *q, int value)
{
    q->arr[q->rear++] = value;
}

int dequeue(Queue *q)
{
    return q->arr[q->front++];
}

bool isIncreasingByOne(Queue *q)
{
    while (q->rear - q->front > 1)
    {
        int first = dequeue(q);
        int second = q->arr[q->front];
        if (second - first != 1)
            return false;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    Queue q = createQueue(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (isIncreasingByOne(&q))
        printf("True\n");
    else
        printf("False\n");

    free(q.arr);
    return 0;
}
