// Đếm số lần xuất hiện số x trong mảng
#include <bits/stdc++.h>
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
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}