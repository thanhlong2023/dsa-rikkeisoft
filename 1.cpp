#include <stdio.h>

#define MAX 100

int visited[MAX];
int queue[MAX], front = -1, rear = -1;

// Danh sách kề dạng mảng 2 chiều
int adj[MAX][MAX]; // adj[u][v] = đỉnh kề thứ v của u
int adjSize[MAX];  // số lượng đỉnh kề của mỗi đỉnh

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

void printQueue() {
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void BFS(int start) {
    enqueue(start);
    visited[start] = 1;
    printf("Start BFS from %d\n", start);

    while (!isEmpty()) {
        printQueue(); // debug hàng đợi

        int current = dequeue();
        printf("Dequeue %d - Visit\n", current);

        for (int i = 0; i < adjSize[current]; i++) {
            int neighbor = adj[current][i];
            if (!visited[neighbor]) {
                printf("  Found neighbor %d of %d → enqueue\n", neighbor, current);
                enqueue(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int main() {
    int n = 4; // số đỉnh

    // Tạo danh sách kề cho đồ thị:
    // 0 - 1, 0 - 2
    adj[0][adjSize[0]++] = 1;
    adj[0][adjSize[0]++] = 2;

    // 1 - 0, 1 - 3
    adj[1][adjSize[1]++] = 0;
    adj[1][adjSize[1]++] = 3;

    // 2 - 0
    adj[2][adjSize[2]++] = 0;

    // 3 - 1
    adj[3][adjSize[3]++] = 1;

    BFS(0);

    return 0;
}
