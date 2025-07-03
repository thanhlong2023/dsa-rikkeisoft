
#include <stdio.h>

// Hàm tìm kiếm nhị phân, trả về vị trí (tính từ 1) hoặc -1 nếu không tìm thấy
int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid + 1; // vị trí tính từ 1
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
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

    int pos = binarySearch(arr, n, x);
    if (pos == -1)
        printf("Khong ton tai phan tu\n");
    else
        printf("phan tu vi tri thu %d\n", pos);

    return 0;
}

// Độ phức tạp thời gian: O(log n)