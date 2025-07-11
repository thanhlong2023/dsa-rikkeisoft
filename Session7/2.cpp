#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}
int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000)
    {
        printf("Invalid input\n");
        return 0;
    }
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("before: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}