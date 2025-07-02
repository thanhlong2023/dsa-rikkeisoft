#include <stdio.h>

// Hàm hoán đổi hai số
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp tăng dần
void sortAsc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(&arr[i], &arr[j]);
}

// Hàm sắp xếp giảm dần
void sortDesc(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
                swap(&arr[i], &arr[j]);
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 1000)
    {
        printf("Input khong hop le\n");
        return 0;
    }
    int arr[1000], even[1000], odd[1000];
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
            even[evenCount++] = arr[i];
        else
            odd[oddCount++] = arr[i];
    }

    sortAsc(even, evenCount);
    sortDesc(odd, oddCount);

    // In mảng kết quả
    printf("[");
    for (int i = 0; i < evenCount; i++)
    {
        printf("%d", even[i]);
        if (i != evenCount - 1 || oddCount > 0)
            printf(", ");
    }
    for (int i = 0; i < oddCount; i++)
    {
        printf("%d", odd[i]);
        if (i != oddCount - 1)
            printf(", ");
    }
    printf("]\n");
    return 0;
}