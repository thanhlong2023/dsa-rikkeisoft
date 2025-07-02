#include <stdio.h>

int main()
{
    int rows, cols, k;
    scanf("%d%d", &rows, &cols);
    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000)
    {
        printf("Input khong hop le\n");
        return 0;
    }
    int arr[1000][1000];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &arr[i][j]);
    scanf("%d", &k);
    if (k < 0 || k >= cols)
    {
        printf("Cot khong hop le\n");
        return 0;
    }
    // Sắp xếp cột k tăng dần (bubble sort)
    for (int i = 0; i < rows - 1; i++)
    {
        for (int j = i + 1; j < rows; j++)
        {
            if (arr[i][k] > arr[j][k])
            {
                // Hoán đổi toàn bộ hàng i và hàng j chỉ ở cột k
                int temp = arr[i][k];
                arr[i][k] = arr[j][k];
                arr[j][k] = temp;
            }
        }
    }
    // In kết quả
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d", arr[i][j]);
            if (j != cols - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}