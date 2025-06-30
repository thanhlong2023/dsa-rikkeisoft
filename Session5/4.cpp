#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm đệ quy tính tổng từ a đến b
int sumRange(int a, int b)
{
    if (a > b)
        return 0;
    if (a == b)
        return a;
    return a + sumRange(a + 1, b);
}

int main()
{
    int firstInput, secondInput;
    cout << "Nhap firstNum: ";
    cin >> firstInput;
    cout << "Nhap secondNum: ";
    cin >> secondInput;

    int result = sumRange(firstInput, secondInput);
    cout << result << endl;
    return 0;
}

// sumRange: Thời gian O(n), không gian O(n) với n = secondNum - firstNum