#include <stdio.h>

// Hàm sắp xếp chọn (Selection Sort)
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
        // Hoán đổi phần tử nhỏ nhất với phần tử ở vị trí i
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
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf(" ]\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    selectionSort(arr, n);

    printArray(arr, n);

    return 0;
}

// Độ phức tạp thời gian: O(n^2)