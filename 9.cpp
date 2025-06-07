#include <iostream>
using namespace std;

// Hàm in toàn bộ phần tử trong ma trận
void printMatrix(int a[][100], int n, int m)
{
    for (int i = 0; i < n; i++)
    { // O(n)
        for (int j = 0; j < m; j++)
        { // O(m)
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    // Thời gian: O(n*m), không gian: O(1) (không tính ma trận truyền vào)
}

// Hàm in toàn bộ phần tử trên đường chéo chính (chỉ áp dụng cho ma trận vuông)
void printMainDiagonal(int a[][100], int n)
{
    for (int i = 0; i < n; i++)
    { // O(n)
        cout << a[i][i] << " ";
    }
    cout << endl;
    // Thời gian: O(n)
}

int main()
{
    int n, m;
    cout << "Nhap so dong: ";
    cin >> n;
    cout << "Nhap so cot: ";
    cin >> m;
    int a[100][100];
    cout << "Nhap cac phan tu cua ma tran:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Cac phan tu cua ma tran:\n";
    printMatrix(a, n, m);

    if (n == m)
    {
        cout << "Cac phan tu tren duong cheo chinh: ";
        printMainDiagonal(a, n);
    }
    else
    {
        cout << "Khong co duong cheo chinh vi ma tran khong vuong.\n";
    }

    return 0;
}

// printMatrix: Thời gian O(n*m), không gian O(1) (không tính ma trận truyền vào)
// printMainDiagonal: Thời gian O(n)