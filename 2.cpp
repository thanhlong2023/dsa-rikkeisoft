#include <iostream>
using namespace std;

void printDouble(int n)
{
    int i = 1;
    while (i < n)
    {
        printf("%d\n", i);
        i *= 2;
    }
}

int main()
{
}
// độ phức tạp thời gian - time complexity: O(logN)