#include <stdio.h>
#include <stdlib.h>

// Hàm tìm giá trị lớn nhất trong mảng 2 chiều
int timMax(int **arr, int rows, int cols)
{
    int max = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

// Hàm tìm giá trị nhỏ nhất trong mảng 2 chiều
int timMin(int **arr, int rows, int cols)
{
    int min = arr[0][0];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

int main()
{
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);

    printf("Nhap so cot: ");
    scanf("%d", &cols);

    // Kiểm tra tính hợp lệ
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

    // Cấp phát động mảng 2 chiều
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)malloc(cols * sizeof(int));
    }

    // Nhập mảng
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    // Gọi hàm tìm max, min
    int max = timMax(arr, rows, cols);
    int min = timMin(arr, rows, cols);

    // In kết quả
    printf("max = %d\n", max);
    printf("min = %d\n", min);

    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
