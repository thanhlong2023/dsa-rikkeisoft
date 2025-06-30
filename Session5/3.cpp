#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Hàm đệ quy tính giai thừa của n
int giaiThua(int n)
{
    if (n <= 1)
        return 1;
    return n * giaiThua(n - 1);
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
    int result = giaiThua(n);
    cout << result << endl;
    return 0;
}

// giaiThua: Thời gian O(n), không gian O(n)