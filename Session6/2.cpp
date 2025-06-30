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

// Hàm đệ quy in n số Fibonacci đầu tiên theo thứ tự ngược lại
void printFiboReverse(int n)
{
    if (n == 0)
        return;
    cout << fibonacci(n - 1);
    if (n > 1)
        cout << ", ";
    printFiboReverse(n - 1);
    // Thời gian: O(n*2^n), không gian: O(n)
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
    printFiboReverse(n);
    cout << endl;
    return 0;
}