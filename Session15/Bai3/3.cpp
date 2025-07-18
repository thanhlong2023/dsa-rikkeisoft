#include <stdbool.h> // Để dùng kiểu bool với true / false
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

bool isEmpty(Queue q)
{
    return q.rear < q.front;
}

int main()
{
    // Trường hợp 1: hàng đợi trống
    Queue q1;
    q1.array = NULL;
    q1.front = 0;
    q1.rear = -1;
    q1.capacity = 5;

    printf("%s\n", isEmpty(q1) ? "true" : "false");

    int data[] = {1, 2, 5};
    Queue q2;
    q2.array = data;
    q2.front = 0;
    q2.rear = 2;
    q2.capacity = 5;

    printf("%s\n", isEmpty(q2) ? "true" : "false");

    return 0;
}