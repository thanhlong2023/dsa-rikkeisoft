#include <iostream>
using namespace std;

// Cách 1: Duyệt 2 vòng lặp (Brute-force)
bool hasDuplicateBruteForce(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { // O(n^2)
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return true;
            }
        }
    }
    return false;
    // Không gian: O(1)
}

// Cách 2: Dùng mảng đánh dấu (Counting array)
bool hasDuplicateCounting(int arr[], int n)
{
    bool appeared[1001] = {0}; // Không gian: O(1) (vì kích thước cố định)
    for (int i = 0; i < n; i++)
    { // Thời gian: O(n)
        if (appeared[arr[i]])
        {
            return true;
        }
        appeared[arr[i]] = true;
    }
    return false;
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int arr[1000];
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Cách 1
    if (hasDuplicateBruteForce(arr, n))
        cout << "Co phan tu trung lap (Brute-force)\n";
    else
        cout << "Khong co phan tu trung lap (Brute-force)\n";

    // Cách 2
    if (hasDuplicateCounting(arr, n))
        cout << "Co phan tu trung lap (Counting array)\n";
    else
        cout << "Khong co phan tu trung lap (Counting array)\n";

    return 0;
}

// hasDuplicateBruteForce: Thời gian O(n^2), không gian O(1)
// hasDuplicateCounting: Thời gian O(n), không gian O(1) (vì mảng đánh dấu kích thước cố định)