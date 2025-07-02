#include <stdio.h>
#include <stdlib.h>

// Tính tổng đường chéo chính (luôn có nếu rows và cols hợp lệ)
int tongCheoChinh(int **arr, int rows, int cols)
{
    int tong = 0;
    int min_dim = (rows < cols) ? rows : cols;
    for (int i = 0; i < min_dim; i++)
    {
        tong += arr[i][i];
    }
    return tong;
}

// Tính tổng đường chéo phụ (chỉ khi ma trận vuông)
int tongCheoPhu(int **arr, int n)
{
    int tong = 0;
    for (int i = 0; i < n; i++)
    {
        tong += arr[i][n - i - 1];
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
        printf("So cot va so hang khong hop le\n");
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

    // Nhập phần tử
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Tính và in tổng đường chéo chính
    int sumMain = tongCheoChinh(arr, rows, cols);
    printf("Tong duong cheo chinh = %d\n", sumMain);

    // Nếu là ma trận vuông, tính đường chéo phụ
    if (rows == cols)
    {
        int sumSub = tongCheoPhu(arr, rows);
        printf("Tong duong cheo phu = %d\n", sumSub);
    }
    else
    {
        printf("Khong ton tai duong cheo phu\n");
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
