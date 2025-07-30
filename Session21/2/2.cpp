#include <stdio.h>

void initGraph(int graph[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            graph[i][j] = 0;
}

void addEdge(int graph[4][4], int firstNode, int secondNode)
{
    graph[firstNode][secondNode] = 1;
    graph[secondNode][firstNode] = 1;
}

void printGraph(int graph[4][4])
{
    for (int i = 0; i < 4; ++i)
    {
        printf("[ ");
        for (int j = 0; j < 4; ++j)
        {
            printf("%d", graph[i][j]);
            if (j < 3)
                printf(",  ");
        }
        printf(" ]\n");
    }
}

int main()
{
    int graph[4][4];
    initGraph(graph);

    // In ma trận ban đầu
    printGraph(graph);
    printf("\n");

    // Thêm các cạnh
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    // In ma trận sau khi thêm cạnh
    printGraph(graph);

    return 0;
}