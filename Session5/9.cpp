#include <iostream>
using namespace std;

// Hàm đệ quy tính số đường đi từ (0,0) đến (row-1, col-1)
int countPaths(int row, int col)
{
    // Nếu chỉ còn 1 hàng hoặc 1 cột thì chỉ có 1 đường đi duy nhất
    if (row == 1 || col == 1)
        return 1;
    // Tổng số đường đi là tổng đường đi khi đi xuống và đi sang phải
    return countPaths(row - 1, col) + countPaths(row, col - 1);
    // Thời gian: O(2^(row+col)), không gian: O(row+col) do ngăn xếp đệ quy
}

int main()
{
    int row, col;
    cin >> row >> col;
    if (row <= 0 || col <= 0)
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }
    int result = countPaths(row, col);
    cout << result << endl;
    return 0;
}

// countPaths: Thời gian O(2^(row+col)), không gian O(row+