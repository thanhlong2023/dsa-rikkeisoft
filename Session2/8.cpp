#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 0 || n > 100)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxRight = a[n - 1];
    cout << maxRight << " "; // phần tử cuối cùng luôn được chọn

    // Duyệt từ phần tử kế cuối về đầu
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxRight)
        {
            cout << a[i] << " ";
            maxRight = a[i];
        }
    }

    return 0;
}
