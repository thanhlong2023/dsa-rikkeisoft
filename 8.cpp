#include <iostream>
using namespace std;

// Hàm tìm phần tử xuất hiện nhiều nhất trong mảng (0 <= arr[i] <= 1000)
int findMostFrequent(int arr[], int n)
{
    int count[1001] = {0}; // Không gian: O(1) (kích thước cố định)
    for (int i = 0; i < n; i++)
    { // Thời gian: O(n)
        count[arr[i]]++;
    }
    int maxCount = 0, result = arr[0];
    for (int i = 0; i <= 1000; i++)
    { // Thời gian: O(1)
        if (count[i] > maxCount)
        {
            maxCount = count[i];
            result = i;
        }
    }
    return result;
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

    int mostFrequent = findMostFrequent(arr, n);
    cout << "Phan tu xuat hien nhieu nhat la: " << mostFrequent << endl;
    return 0;
}

// findMostFrequent: Độ phức tạp thời gian O(n), không gian O(1) (vì mảng đếm kích thước cố định)