#include <iostream>
using namespace std;

// Hàm đệ quy tìm giá trị nhỏ nhất trong mảng
int findMin(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int minRest = findMin(arr, n - 1);
    if (arr[n - 1] < minRest)
        return arr[n - 1];
    else
        return minRest;
}

// Hàm đệ quy tìm giá trị lớn nhất trong mảng
int findMax(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int maxRest = findMax(arr, n - 1);
    return arr[n - 1] > maxRest ? arr[n - 1] : maxRest;
}

int main()
{
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Input khong hop le" << endl;
        return 0;
    }
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int minVal = findMin(arr, n);
    int maxVal = findMax(arr, n);
    cout << minVal << ", " << maxVal << endl;
    return 0;
}

// findMin, findMax: Thời gian O(n), không gian O(n)