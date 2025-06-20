/*Input

Output

[-1,5,-3,2], vị trí: 2, giá trị: 8

[-1,5,8,-3,2]*/
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
    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int position, value;
    cin >> position;
    if (position < 0 || position >= n)
    {
        cout << "Invalid position" << endl;
        return 0;
    }
    cin >> value;
    for (int i = n; i > position; i--)
    {
        a[i] = a[i - 1];
    }
    a[position] = value;
    n++;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}