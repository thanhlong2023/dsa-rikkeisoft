#include <iostream>
using namespace std;

// Hàm đệ quy tính số đường đi từ (curRow, curCol) đến (row-1, col-1), tránh ô bị chặn
int countPaths(int row, int col, int blockedRow, int blockedCol, int curRow = 0, int curCol = 0)
{
    // Nếu ra ngoài biên hoặc vào ô bị chặn thì không có đường đi
    if (curRow >= row || curCol >= col || (curRow == blockedRow && curCol == blockedCol))
        return 0;
    // Nếu đến đích thì có 1 đường đi
    if (curRow == row - 1 && curCol == col - 1)
        return 1;
    // Đệ quy: đi xuống hoặc sang phải
    return countPaths(row, col, blockedRow, blockedCol, curRow + 1, curCol) + countPaths(row, col, blockedRow, blockedCol, curRow, curCol + 1);
    // Thời gian: O(2^(row+col)), không gian: O(row+col)
}

int main()
{
    int row, col, blockedRow, blockedCol;
    cout << "Nhap so hang: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> col;
    cout << "Nhap hang cua o bi chan: ";
    cin >> blockedRow;
    cout << "Nhap cot cua o bi chan: ";
    cin >> blockedCol;

    if (row <= 0 || col <= 0 || blockedRow < 0 || blockedRow >= row || blockedCol < 0 || blockedCol >= col)
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }

    int result = countPaths(row, col, blockedRow, blockedCol);
    cout << result << endl;
    return 0;
}
