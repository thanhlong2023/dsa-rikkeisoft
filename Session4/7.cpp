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

    bool found = false;
    for (int i = 0; i < n / 2; ++i)
    {
        if (arr[i] == arr[n - 1 - i])
        {
            cout << "Cap doi xung: (" << arr[i] << ", " << arr[n - 1 - i] << ")\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong co phan tu doi xung\n";
    }

    return 0;
}
