#include <iostream>
using namespace std;

// Hàm đệ quy in số ở dạng nhị phân
void printBinary(int n)
{
    if (n == 0)
        return;
    printBinary(n / 2);
    cout << n % 2;
    // Thời gian: O(log n), không gian: O(log n)
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
    printBinary(n);
    cout << endl;
    return 0;
}