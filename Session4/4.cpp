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

    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;

    int lastIndex = -1;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
        {
            lastIndex = i;
        }
    }

    if (lastIndex != -1)
    {
        cout << lastIndex << endl;
    }
    else
    {
        cout << "Khong tim thay phan tu" << endl;
    }

    return 0;
}
