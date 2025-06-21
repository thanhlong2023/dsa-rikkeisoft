#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
};

// Chuyển chuỗi về chữ thường
string toLowerCase(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Kiểm tra xem chuỗi con có nằm trong chuỗi cha (không phân biệt hoa thường)
bool containsIgnoreCase(string fullName, string keyword)
{
    fullName = toLowerCase(fullName);
    keyword = toLowerCase(keyword);
    return fullName.find(keyword) != string::npos;
}

int main()
{
    const int SIZE = 5;
    Student students[SIZE];

    cout << "Nhap thong tin cho 5 sinh vien:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Sinh vien " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> students[i].id;
        cin.ignore(); // Xóa '\n' sau khi nhập số
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Age: ";
        cin >> students[i].age;
    }

    string keyword;
    cout << "\nNhap ten sinh vien can tim (co the nhap mot phan): ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    cout << "\nSinh vien tim duoc:\n";
    for (int i = 0; i < SIZE; ++i)
    {
        if (containsIgnoreCase(students[i].name, keyword))
        {
            cout << "{ id: " << students[i].id
                 << ", name: \"" << students[i].name
                 << "\", age: " << students[i].age << " }\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay sinh vien nao phu hop.\n";
    }

    return 0;
}
