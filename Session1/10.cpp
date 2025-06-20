#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Cách 1: Sắp xếp 2 chuỗi rồi so sánh
bool isPermutationSort(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end()); // O(n log n)
    sort(s2.begin(), s2.end()); // O(n log n)
    return s1 == s2;
    // Thời gian: O(n log n), không gian: O(1) (nếu không tính bộ nhớ sort)
}

// Cách 2: Đếm số lần xuất hiện ký tự (Counting array)
bool isPermutationCount(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    int count[256] = {0}; // Giả sử ký tự ASCII, không gian: O(1)
    for (char c : s1) count[(unsigned char)c]++; // O(n)
    for (char c : s2) count[(unsigned char)c]--; // O(n)
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) return false;
    }
    return true;
    // Thời gian: O(n), không gian: O(1)
}

int main() {
    string s1, s2;
    cout << "Nhap chuoi 1: ";
    cin >> s1;
    cout << "Nhap chuoi 2: ";
    cin >> s2;

    // Cách 1
    if (isPermutationSort(s1, s2))
        cout << "Cach 1: Hai chuoi la hoan vi cua nhau\n";
    else
        cout << "Cach 1: Hai chuoi khong la hoan vi cua nhau\n";

    // Cách 2
    if (isPermutationCount(s1, s2))
        cout << "Cach 2: Hai chuoi la hoan vi cua nhau\n";
    else
        cout << "Cach 2: Hai chuoi khong la hoan vi cua nhau\n";

    return 0;
}

// isPermutationSort: Thời gian O(n log n), không gian O(1) (nếu không tính bộ nhớ sort)
// isPermutationCount: Thời gian O(n), không gian O(1) (với bảng đếm ký tự kích thước cố định)