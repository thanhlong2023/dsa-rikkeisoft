#include <stdio.h>
#include <stdlib.h>

// Hàm tính trung bình cộng các số chẵn trong mảng
float tinhTrungBinhChan(int *arr, int n)
{
    int tong = 0;
    int dem = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            tong += arr[i];
            dem++;
        }
    }

    if (dem == 0)
        return 0; // Tránh chia cho 0
    return (float)tong / dem;
}

int main()
{
    int n;

    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);

    // Kiểm tra hợp lệ
    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    // Cấp phát động mảng
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

    // Gọi hàm và in kết quả
    float average = tinhTrungBinhChan(arr, n);
    printf("average = %.0f\n", average); // In không lấy phần thập phân như ví dụ

    // Giải phóng bộ nhớ
    free(arr);

    return 0;
}
