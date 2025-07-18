#include <stdio.h>
#include <stdlib.h>

// Cấu trúc hàng đợi
typedef struct
{
    int *arr;     // Mảng lưu phần tử
    int front;    // Chỉ số phần tử đầu tiên
    int rear;     // Chỉ số phần tử cuối cùng
    int capacity; // Sức chứa tối đa
} Queue;

Queue createQueue(int maxSize)
{
    Queue q;
    q.arr = (int *)malloc(sizeof(int) * maxSize); // Cấp phát mảng
    q.front = 0;
    q.rear = -1;
    q.capacity = maxSize;
    return q;
}

int main()
{
    int size = 5;
    Queue myQueue = createQueue(size);

    printf("Queue initialized:\n");
    printf("Front = %d\n", myQueue.front);
    printf("Rear = %d\n", myQueue.rear);
    printf("Capacity = %d\n", myQueue.capacity);

    free(myQueue.arr); // Giải phóng bộ nhớ
    return 0;
}
