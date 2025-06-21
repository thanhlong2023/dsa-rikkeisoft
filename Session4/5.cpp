#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Hàm tìm kiếm nhị phân
bool binarySearch(const vector<int> &arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr[mid] == x)
            return true;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Sắp xếp mảng
    sort(arr.begin(), arr.end());

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    // Tìm kiếm nhị phân
    if (binarySearch(arr, x))
    {
        cout << "Phan tu co trong mang" << endl;
    }
    else
    {
        cout << "Phan tu khong co trong mang" << endl;
    }

    return 0;
}
