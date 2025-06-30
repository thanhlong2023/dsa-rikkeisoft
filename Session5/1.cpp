#include <iostream>
using namespace std;

// Hàm đệ quy in các số từ 1 đến n
void printNumbers(int n)
{
    if (n == 0)
        return;          // Điều kiện dừng
    printNumbers(n - 1); // Đệ quy in các số nhỏ hơn n
    cout << n << " ";    // In số hiện tại
    // Thời gian: O(n), không gian: O(n) (do ngăn xếp đệ quy)
}

int main()
{
    int n;
    cout << "Nhap so nguyen duong n: ";
    cin >> n;
    if (n <= 0)
    {
        return 0;
    }
    printNumbers(n);
    cout << endl;
    return 0;
}

// printNumbers: Thời gian O(n), không