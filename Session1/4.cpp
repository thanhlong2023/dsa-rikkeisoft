#include <iostream>
using namespace std;

int sumLoop(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    { // Thời gian: O(n)
        sum += i;
    }
    return sum;
}

int sumFormula(int n)
{
    return n * (n + 1) / 2; // Thời gian: O(1)
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    cout << "Tong bang vong lap: " << sumLoop(n) << endl;     // O(n)
    cout << "Tong bang cong thuc: " << sumFormula(n) << endl; // O(1)
    return 0;
}

// sumLoop: Độ phức tạp thời gian O(n), không gian O(1)
// sumFormula: Độ phức tạp thời gian O(1), không gian O(1)