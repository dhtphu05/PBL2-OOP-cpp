#include <iostream>
#include <conio.h>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "../../Template/DoubleLinkedList.h"
#include "../../Include/Admin.h"
#include "../../Include/Staff.h"
#include "../../Include/Customer.h"
using namespace std;

template <class T>
void getInf(DoubleLinkedList<T> &list, ifstream &in)
{
    string line;
    while (getline(in, line))
    {
        stringstream ss(line);
        T m;
        getline(ss, m.getID(), ';');
        getline(ss, m.getUserName(), ';');
        getline(ss, m.getPassword(), ';');
        getline(ss, m.getFullName(), ';');
        getline(ss, m.getPhoneNumber(), ';');
        getline(ss, m.getDOB(),';');
        getline(ss, m.getGender());
        list.push_back(m);
    }
}
void getPassword(string &password)
{
    char ch;
    cout << "Nhap mat khau: ";
    while ((ch = _getch()) != '\r')
    { // '\r' là ký tự Enter
        if (ch == '\b')
        { // Xử lý khi nhấn phím Backspace
            if (!password.empty())
            {
                cout << "\b \b";
                password.pop_back();
            }
        }
        else
        {
            password += ch;
            cout << '*';
        }
    }
    cout << endl; // Xuống dòng sau khi nhập xong
}
void readFileManagement(int i, DoubleLinkedList<Admin> &adminList, DoubleLinkedList<Staff> &staffList, DoubleLinkedList<Customer> &customerList)
{
    ifstream in;

    if (i == 1)
    {
        in.open("../../TEXT/AdminList.txt");
        if (!in.is_open())
        {
            throw runtime_error("Error opening file");
        }
        getInf<Admin>(adminList, in);
    }
    else if (i == 2)
    {
        in.open("../../TEXT/StaffList.txt");
        if (!in.is_open())
        {
            throw runtime_error("Error opening file");
        }
        getInf<Staff>(staffList, in);
    }
    else if (i == 3)
    {
        cout << "Ban khong co quyen truy cap" << endl;
        // in.open("../../TEXT/CustomerList.txt");
        // if (!in.is_open()) {
        //     throw runtime_error("Error opening file");
        // }
        // getInf<Customer>(customerList, in);
    }
    in.close();
}

void logIn()
{
    cout << "Ban dang nhap voi tu cach la: " << endl;
    cout << "1. Admin" << endl;
    cout << "2. Staff" << endl;
    cout << "3. Customer" << endl;
    cout << "4. Thoat" << endl;

    int choice;
    cout << "Nhap lua chon: ";
    cin >> choice;

    string userName;
    string password;
    cout << "Nhap ten dang nhap: ";
    cin >> userName;
    getPassword(password);
 

    DoubleLinkedList<Admin> adminList;
    DoubleLinkedList<Staff> staffList;
    DoubleLinkedList<Customer> customerList;

    // Đọc danh sách người dùng
    readFileManagement(1, adminList, staffList, customerList); // Đọc Admin
    bool loggedIn = false;

    // Kiểm tra thông tin đăng nhập
    if (choice == 1)
    { // Admin
        for (int i = 0; i < adminList.getSize(); i++)
        {
            if (adminList[i].username == userName && adminList[i].password == password)
            {
                cout << "Chao " << adminList[i].getFullName() << "!" << endl;
                loggedIn = true;
                break;
            }
        }
    }
    else if (choice == 2)
    { // Staff
        for (int i = 0; i < staffList.getSize(); i++)
        {
            if (staffList[i].getUserName() == userName && staffList[i].getPassword() == password)
            {
                cout << "Chao " << staffList[i].getFullName() << "!" << endl;
                loggedIn = true;
                break;
            }
        }
    }
    else if (choice == 3)
    { // Customer
        for (int i = 0; i < customerList.getSize(); i++)
        {
            if (customerList[i].getUserName() == userName && customerList[i].getPassword() == password)
            {
                cout << "Chao " << customerList[i].getFullName() << "!" << endl;
                loggedIn = true;
                break;
            }
        }
    }

    if (!loggedIn)
    {
        cout << "Ten dang nhap hoac mat khau khong chinh xac." << endl;
    }
}
