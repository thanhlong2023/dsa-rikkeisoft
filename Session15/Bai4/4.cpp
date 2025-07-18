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
void viewQueue(Queue q)
{
    if (q.front > q.rear)
    {
        printf("queue is empty\n");
        return;
    }

    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d\n", q.array[i]);
    }
}
int main()
{
    Queue q1 = {{}, 0, -1, 5};
    viewQueue(q1);
    // Output: queue is empty

    Queue q2 = {{1, 2, 5}, 0, 2, 5};
    viewQueue(q2);
    // Output:
    // 1
    // 2
    // 5

    return 0;
}
