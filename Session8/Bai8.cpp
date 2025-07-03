#include <stdio.h>

// Hàm sắp xếp chèn (Insertion Sort)
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Hàm tìm kiếm tuyến tính (Linear Search)
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i; // trả về chỉ số đầu tiên tìm thấy
    return -1;
}

// Hàm tìm kiếm nhị phân (Binary Search)
int binarySearch(int arr[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Hàm in mảng
void printArray(const int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n - 1)
            printf(", ");
    }
    printf(" ]\n");
}

int main()
{
    int n;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000)
    {
        printf("So luong phan tu khong hop le\n");
        return 0;
    }
    int arr[1000];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Mang sau khi sap xep: ");
    printArray(arr, n);

    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    int posLinear = linearSearch(arr, n, x);
    int posBinary = binarySearch(arr, n, x);

    if (posLinear != -1)
        printf("Linear Search: Tim thay %d tai vi tri %d\n", x, posLinear + 1);
    else
        printf("Linear Search: Khong tim thay %d\n", x);

    if (posBinary != -1)
        printf("Binary Search: Tim thay %d tai vi tri %d\n", x, posBinary + 1);
    else
        printf("Binary Search: Khong tim thay %d\n", x);

    return 0;
}