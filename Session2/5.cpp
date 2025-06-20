/*Input

Output

[-1,5,-3,2,10], 2

[-1,5,2,10]*/

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
    int indexDelete;
    cin >> indexDelete;
    if (indexDelete < 0 || indexDelete >= n)
    {
        cout << "Invalid indexDelete" << endl;
        return 0;
    }
    for (int i = indexDelete; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    n--;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}