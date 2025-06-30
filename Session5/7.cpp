#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ k
int fibonacci(int k)
{
    if (k == 0)
        return 0;
    if (k == 1)
        return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
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
    int result[100];
    for (int i = 0; i < n; i++)
    {
        result[i] = fibonacci(i);
    }
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        cout << result[i];
        if (i != n - 1)
            cout << ",";
    }
    cout << "]" << endl;
    return 0;
}

// fibonacci: Thời gian O(2^n) cho mỗi số, tổng O(n*2^n), không gian O(n) cho mảng kết quả