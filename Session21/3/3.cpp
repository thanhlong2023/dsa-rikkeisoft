#include <stdio.h>

void initGraph(int graph[3][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            graph[i][j] = 0;
}

// Thêm cạnh có hướng từ startNode đến endNode
void addEdge(int graph[3][3], int startNode, int endNode)
{
    graph[startNode][endNode] = 1;
}

void printGraph(int graph[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        printf("[ ");
        for (int j = 0; j < 3; ++j)
        {
            printf("%d", graph[i][j]);
            if (j < 2)
                printf(",  ");
        }
        printf(" ]\n");
    }
}

int main()
{
    int graph[3][3];
    initGraph(graph);

    // In ma trận ban đầu
    printGraph(graph);
    printf("\n");

    // Thêm cạnh có hướng từ node 1 đến node 2
    addEdge(graph, 1, 2);

    // In ma trận sau khi thêm cạnh
    printGraph(graph);

    return 0;
}