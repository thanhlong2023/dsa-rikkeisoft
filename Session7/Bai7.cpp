#include <stdio.h>

// Hàm hoán đổi hai số
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp: số âm đầu, số 0 giữa, số dương cuối
void customSort(int arr[], int n)
{
    int left = 0, right = n - 1, i = 0;
    // Đưa số âm về đầu, số dương về cuối, 0 ở giữa (biến thể Dutch National Flag)
    while (i <= right)
    {
        if (arr[i] < 0)
        {
            swap(&arr[i], &arr[left]);
            left++;
            i++;
        }
        else if (arr[i] > 0)
        {
            swap(&arr[i], &arr[right]);
            right--;
        }
        else
        {
            i++;
        }
    }
}

// Hàm in mảng theo định dạng yêu cầu
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
        printf("Số lượng phần tử không hợp lệ\n");
        return 0;
    }
    int arr[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("before: ");
    printArray(arr, n);

    customSort(arr, n);

    printf("after: ");
    printArray(arr, n);

    return 0;
}