/*Input

Output

[-1,5,-3,2,10], position: 0, value: 3

[3,5,-3,2,10]*/
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
    for (int i = 0; i < n; i++)
    {
        if (i == position)
        {
            a[i] = value;
            break;
        }
    }

    return 0;
}