#include <iostream>
#include <vector>
using namespace std;

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

    // Khởi tạo giá trị nhỏ nhất và chỉ số
    int minVal = arr[0];
    int minIndex = 0;

    for (int i = 1; i < n; ++i)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
            minIndex = i;
        }
    }

    cout << minIndex << endl;
    return 0;
}
