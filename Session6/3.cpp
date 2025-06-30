#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số của n
int sumDigits(int n)
{
    if (n == 0)
        return 0;
    return n % 10 + sumDigits(n / 10);
    // Thời gian: O(log n), không gian: O(log n)
}

int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }
    cout << sumDigits(n) << endl;
    return 0;
}