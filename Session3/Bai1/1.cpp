#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("So luong phan tu khong duoc am\n");
        return 1;
    }
    else if (n == 0)
    {
        printf("So luong phan tu phai lon hon 0\n");
        return 1;
    }

    // Cấp phát động cho mảng n phần tử kiểu int
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    // Nhập giá trị các phần tử
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In ra giá trị các phần tử
    for (int i = 0; i < n; i++)
    {
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
