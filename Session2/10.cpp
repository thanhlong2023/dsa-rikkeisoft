#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid input" << endl;
        return 0;
    }

    int a[100];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        // Kiểm tra a[i] đã xuất hiện trước đó chưa
        bool isCounted = false;
        for (int j = 0; j < i; j++)
        {
            if (a[j] == a[i])
            {
                isCounted = true;
                break;
            }
        }

        if (!isCounted)
        {
            // Đếm số lần xuất hiện
            int count = 0;
            for (int k = 0; k < n; k++)
            {
                if (a[k] == a[i])
                    count++;
            }

            cout << "Phan tu " << a[i] << " xuat hien " << count << " lan" << endl;
        }
    }

    return 0;
}
