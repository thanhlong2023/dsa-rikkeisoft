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

    int maxCount = 0;
    int result = a[0];

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        // Đếm số lần xuất hiện của a[i]
        for (int j = 0; j < n; j++)
        {
            if (a[j] == a[i])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            result = a[i];
        }
        // nếu count == maxCount thì bỏ qua để giữ phần tử đầu tiên
    }

    cout << result << endl;
    return 0;
}
