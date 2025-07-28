#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> ke[1001];

int a[1005][1005];
int n, m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
        cout << i << " : ";
        for (int x : ke[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}