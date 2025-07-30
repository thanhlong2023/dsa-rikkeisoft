#include <stdio.h>
#include <stdlib.h>

// Cấu trúc cho một phần tử trong danh sách liên kết
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Hàm tạo phần tử mới cho danh sách liên kết
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm cạnh giữa hai node trong đồ thị (dạng danh sách liên kết)
void addEdge(Node *graph[], int firstNode, int secondNode)
{
    // Thêm secondNode vào danh sách của firstNode
    Node *node1 = createNode(secondNode);
    node1->next = graph[firstNode];
    graph[firstNode] = node1;

    // Thêm firstNode vào danh sách của secondNode (vì là đồ thị vô hướng)
    Node *node2 = createNode(firstNode);
    node2->next = graph[secondNode];
    graph[secondNode] = node2;
}

// Hàm in đồ thị dưới dạng danh sách liên kết
void printGraph(Node *graph[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("[ ");
        Node *temp = graph[i];
        if (!temp)
        {
            printf("NULL");
        }
        else
        {
            while (temp)
            {
                printf("%d", temp->data);
                if (temp->next)
                    printf("->");
                temp = temp->next;
            }
            printf("->NULL");
        }
        printf(" ]\n");
    }
}

int main()
{
    int n = 3;
    Node *graph[3] = {NULL, NULL, NULL};

    // In ma trận ban đầu
    printGraph(graph, n);
    printf("\n");

    // Thêm cạnh giữa node 1 và 2
    addEdge(graph, 1, 2);
    printGraph(graph, n);
    printf("\n");

    // Thêm cạnh giữa node 0 và 1
    addEdge(graph, 0, 1);
    printGraph(graph, n);

    // Giải phóng bộ nhớ
    for (int i = 0; i < n; ++i)
    {
        Node *temp = graph[i];
        while (temp)
        {
            Node *next = temp->next;
            free(temp);
            temp = next;
        }
    }
    return 0;
}