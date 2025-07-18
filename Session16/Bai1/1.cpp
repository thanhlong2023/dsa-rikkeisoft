#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
};
typedef struct
{
    Node *front;
    Node *rear;
} Queue;
Queue createQueue()
{
    Queue q;
    q.front = NULL;
    q.rear = NULL;
    return q;
}

int main()
{
    Queue q = createQueue();
    if (q.front == NULL && q.rear == NULL)
    {
        printf("Hàng đợi khởi tạo thành công và đang rỗng.\n");
    }

    return 0;
}