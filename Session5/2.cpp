#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm đệ quy tính tổng từ 1 đến n
int sumRecursive(int n)
{
    if (n <= 0)
        return 0;
    return n + sumRecursive(n - 1);
}

int main()
{
    string input;
    cout << "Nhap mot chuoi: ";
    cin >> input;

    // Kiểm tra input có phải số nguyên dương không
    bool isNumber = true;
    for (char c : input)
    {
        if (!isdigit(c))
        {
            isNumber = false;
            break;
        }
    }

    if (!isNumber || input.empty() || stoi(input) <= 0)
    {
        cout << "Khong hop le" << endl;
        return 0;
    }

    int n = stoi(input);
    int result = sumRecursive(n);
    cout << result << endl;
    return 0;
}

// sumRecursive: Thời gian O(n), không gian