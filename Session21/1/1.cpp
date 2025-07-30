#include <stdio.h>

void initGraph(int graph[3][3])
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            graph[i][j] = 0;
}

void addEdge(int graph[3][3], int firstNode, int secondNode)
{
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
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

    // Thêm cạnh giữa node 1 và 2
    addEdge(graph, 1, 2);

    // In ma trận sau khi thêm cạnh
    printGraph(graph);

    return 0;
}