#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Hàm đệ quy chuyển đổi chuỗi số thành số nguyên
int stringToInt(const string &s, int idx = 0)
{
    if (idx == s.length())
        return 0;
    return (s[idx] - '0') * pow(10, s.length() - idx - 1) + stringToInt(s, idx + 1);
}

// Hàm kiểm tra chuỗi có phải toàn số không
bool isNumber(const string &s)
{
    if (s.empty())
        return false;
    for (char c : s)
    {
        if (!isdigit(c))
            return false;
    }
    return true;
}

int main()
{
    string input;
    cin >> input;

    // Kiểm tra số âm
    bool isNegative = false;
    int startIdx = 0;
    if (!input.empty() && input[0] == '-')
    {
        isNegative = true;
        startIdx = 1;
    }

    string numPart = input.substr(startIdx);

    if (!isNumber(numPart))
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }

    int result = stringToInt(numPart);
    if (isNegative)
        result = -result;
    cout << result << endl;
    return 0;
}

// stringToInt: Thời gian O(n), không gian