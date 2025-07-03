#include <stdio.h>

int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i + 1;
    }
    return -1; // không tìm thấy
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
    int x;
    scanf("%d", &x);

    int pos = linearSearch(arr, n, x);
    if (pos == -1)
        printf("Khong ton tai phan tu\n");
    else
        printf("vi tri thu %d\n", pos);

    return 0;
}

// Độ phức tạp thời gian: O(n)