#include <stdio.h>

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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

    insertionSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}