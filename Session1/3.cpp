#include <iostream>
using namespace std;

int *mallocArray(int n)
{
    int *arr = (int *)malloc(n * sizeof(int)); // Thời gian: O(1), Không gian: O(n)
    for (int i = 0; i < n; i++)
    {
        arr[i] = i; // Thời gian: O(n)
    }
    return arr;
}
// Độ phức tạp thời gian - Time complexity: O(n)
// Độ phức tạp không gian - Space complexity: O(n)