#include <iostream>
using namespace std;

// Hàm đệ quy giải bài toán tháp Hà Nội
void hanoi(int n, char from, char to, char aux)
{
    if (n == 0)
        return;
    hanoi(n - 1, from, aux, to);
    cout << "Đĩa " << n << " di chuyển từ " << from << " sang " << to << endl;
    hanoi(n - 1, aux, to, from);
    // Thời gian: O(2^n), không gian: O(n)
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
    hanoi(n, 'A', 'C', 'B');
    return 0;
}