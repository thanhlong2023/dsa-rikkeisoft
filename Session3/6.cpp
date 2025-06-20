#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;

    // Nhập số lượng phần tử ban đầu
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    // Kiểm tra hợp lệ
    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    // Cấp phát bộ nhớ cho n phần tử
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("Cap phat bo nho that bai\n");
        return 1;
    }

    // Nhập n phần tử
    for (int i = 0; i < n; i++)
    {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập số phần tử thêm vào
    printf("Nhap so luong phan tu muon them m: ");
    scanf("%d", &m);

    if (m < 0 || (n + m) > 1000)
    {
        printf("So luong phan tu sau khi them khong hop le\n");
        free(arr);
        return 1;
    }

    // Cấp phát lại bộ nhớ để chứa n + m phần tử
    int *temp = (int *)realloc(arr, (n + m) * sizeof(int));
    if (temp == NULL)
    {
        printf("Cap phat bo nho lan 2 that bai\n");
        free(arr);
        return 1;
    }
    arr = temp;

    // Nhập m phần tử thêm vào
    for (int i = 0; i < m; i++)
    {
        printf("Nhap phan tu them thu %d: ", i + 1);
        scanf("%d", &arr[n + i]);
    }

    // In kết quả sau khi thêm
    printf("[ ");
    for (int i = 0; i < n + m; i++)
    {
        printf("%d", arr[i]);
        if (i < n + m - 1)
        {
            printf(", ");
        }
    }
    printf(" ]\n");

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
