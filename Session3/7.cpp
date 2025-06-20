#include <stdio.h>
#include <stdlib.h>

// Hàm tính tổng các phần tử của hàng k (tính từ 0)
int tinhTongHang(int **arr, int cols, int k)
{
    int tong = 0;
    for (int j = 0; j < cols; j++)
    {
        tong += arr[k][j];
    }
    return tong;
}

int main()
{
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);

    printf("Nhap so cot: ");
    scanf("%d", &cols);

    // Kiểm tra hợp lệ
    if (rows <= 0 && cols <= 0)
    {
        printf("So hang va so cot khong hop le\n");
        return 1;
    }
    else if (rows <= 0)
    {
        printf("So hang khong hop le\n");
        return 1;
    }
    else if (cols <= 0)
    {
        printf("So cot khong hop le\n");
        return 1;
    }

    // Cấp phát mảng 2 chiều
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Nhập phần tử mảng
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Nhập hàng k (đánh số từ 1)
    int k;
    printf("Nhap so hang k can tinh tong (bat dau tu 1): ");
    scanf("%d", &k);

    if (k < 1 || k > rows)
    {
        printf("Hang can tinh khong ton tai\n");
    }
    else
    {
        int sum = tinhTongHang(arr, cols, k - 1); // chuyển sang chỉ số 0
        printf("sum = %d\n", sum);
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
