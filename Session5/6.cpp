#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng mảng
int sumArray(int arr[], int n)
{
    if (n == 0)
        return 0;
    return arr[n - 1] + sumArray(arr, n - 1);
    // Thời gian: O(n), không gian: O(n)
}

int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Khong hop le" << endl;
        return 0;
    }
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = sumArray(arr, n);
    cout << result << endl;
    return 0;
}