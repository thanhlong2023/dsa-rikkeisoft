#include <iostream>
using namespace std;

// Hàm đếm số lần xuất hiện của x trong mảng arr
int countOccurrences(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    { // Thời gian: O(n)
        if (arr[i] == x)
        {
            count++;
        }
    }
    return count;
    // Không gian: O(1)
}

int main()
{
    int n, x;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int arr[1000]; // Giả sử n <= 1000
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Nhap gia tri can dem: ";
    cin >> x;

    int result = countOccurrences(arr, n, x);
    cout << "So lan xuat hien cua " << x << " la: " << result << endl;
    return 0;
}

// countOccurrences: Độ phức tạp thời gian O(n), không gian O(1)