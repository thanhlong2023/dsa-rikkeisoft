#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    // Kiểm tra tính hợp lệ của n
    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    // Cấp phát động mảng n phần tử
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    // Nhập các phần tử
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Tìm số lớn nhất
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // In kết quả
    printf("max = %d\n", max);

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
