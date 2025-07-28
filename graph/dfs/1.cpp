#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> ke[1001];

int a[1005][1005];
int n, m;
bool visited[1001];

void DFS(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : ke[u])
    {
        if (!visited[v])
        {
            DFS(v);
        }
    }
}

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
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            ++dem;
        }
    }
    cout << "\nSo thanh phan lien thong: " << dem << endl;
    return 0;
}