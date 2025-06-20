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
    int sum;
    cin >> sum;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == sum)
            {
                cout << a[i] << ", " << a[j] << endl;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    if (!found)
    {
        cout << "Khong tim thay" << endl;
    }

    return 0;
}
