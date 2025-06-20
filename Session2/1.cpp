#include <bits/stdc++.h>
using namespace std;

// tạo mảng có n số, 0< n <= 100, tìm phần tử lớn nhất trong mảng
int main()
{
    int n;
    cin >> n;
    int a[n];
    if (n <= 0 || n > 100)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxElement = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > maxElement)
        {
            maxElement = a[i];
        }
    }
    printf("%d", maxElement);
    return 0;
}
