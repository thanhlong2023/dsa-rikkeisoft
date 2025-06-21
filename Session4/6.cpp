#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
};

int main()
{
    const int SIZE = 5;
    Student students[SIZE];

    // Nhập thông tin 5 sinh viên
    cout << "Nhap thong tin cho 5 sinh vien:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Sinh vien " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore(); // Xóa kí tự '\n' sau khi nhập số
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Age: ";
        cin >> students[i].age;
    }

    // Nhập ID cần tìm
    int searchId;
    cout << "\nNhap ID can tim: ";
    cin >> searchId;

    // Tìm kiếm sinh viên theo ID
    bool found = false;
    for (int i = 0; i < SIZE; ++i)
    {
        if (students[i].id == searchId)
        {
            cout << "\n{ id: " << students[i].id
                 << ", name: \"" << students[i].name
                 << "\", age: " << students[i].age << " }\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Sinh vien khong ton tai\n";
    }

    return 0;
}
