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

    bool found = false;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == x)
        {
            if (found)
                cout << ", ";
            cout << i;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Phan tu khong co trong mang";
    }

    cout << endl;
    return 0;
}
