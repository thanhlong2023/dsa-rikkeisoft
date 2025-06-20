// đảo ngược mảng

#include <bits/stdc++.h>
using namespace std;

void swapNumber(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void reverseArray(int arr[], int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swapNumber(arr[start], arr[end]);
        start++;
        end--;
    }
}

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
    reverseArray(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}