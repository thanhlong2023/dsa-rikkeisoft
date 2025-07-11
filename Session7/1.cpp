#include <stdio.h>

void bubleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
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

    bubleSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}