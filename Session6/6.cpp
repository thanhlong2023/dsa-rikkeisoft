#include <iostream>
using namespace std;

// Hàm đệ quy đếm số cách leo cầu thang
int countWays(int n)
{
    if (n == 0)
        return 1; // Đã leo hết bậc
    if (n < 0)
        return 0; // Vượt quá số bậc
    return countWays(n - 1) + countWays(n - 2);
    // Thời gian: O(2^n), không gian: O(n)
}

int main()
{
    int n;
    cin >> n;
    if (n < 0)
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }
    cout << countWays(n) << endl;
    return 0;
}