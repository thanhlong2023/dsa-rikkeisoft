#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Tìm kiếm nhị phân đệ quy
bool binarySearchRecursive(const vector<int> &arr, int left, int right, int x)
{
    if (left > right)
        return false;

    int mid = (left + right) / 2;

    if (arr[mid] == x)
        return true;
    else if (arr[mid] < x)
        return binarySearchRecursive(arr, mid + 1, right, x);
    else
        return binarySearchRecursive(arr, left, mid - 1, x);
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Sắp xếp mảng
    sort(arr.begin(), arr.end());

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Gọi tìm kiếm nhị phân đệ quy
    if (binarySearchRecursive(arr, 0, n - 1, x))
    {
        cout << "Phan tu co trong mang" << endl;
    }
    else
    {
        cout << "Phan tu khong co trong mang" << endl;
    }

    return 0;
}
