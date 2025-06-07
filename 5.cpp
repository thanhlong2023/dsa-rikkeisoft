#include <iostream>
using namespace std;

// Hàm sắp xếp nổi bọt (Bubble Sort)
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    { // Thời gian: O(n^2)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Hoán đổi 2 phần tử
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // Không gian: O(1)
}

int main()
{
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    int arr[1000]; // Giả sử n <= 1000
    cout << "Nhap cac phan tu:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

// bubbleSort: Độ phức tạp thời gian O(n^2), không gian O(1)