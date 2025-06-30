#include <iostream>
#include <string>
using namespace std;

// Hàm đệ quy kiểm tra chuỗi đối xứng
bool isPalindrome(const string &s, int left, int right)
{
    if (left >= right)
        return true;
    if (s[left] != s[right])
        return false;
    return isPalindrome(s, left + 1, right - 1);
}

int main()
{
    string input;
    cout << "Nhap mot chuoi: ";
    getline(cin, input);

    if (isPalindrome(input, 0, input.length() - 1))
        cout << "Palindrome valid" << endl;
    else
        cout << "Palindrome invalid" << endl;

    return 0;
}

// isPalindrome: Thời gian O(n), không gian O(n) (do ngăn xếp