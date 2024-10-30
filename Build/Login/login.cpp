#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "../../Template/DoubleLinkedList.h"
#include "../../Include/Admin.h"
#include "../../Include/Staff.h"
#include "../../Include/Customer.h"
using namespace std;

template <class T>
void getInf(DoubleLinkedList<T> &list, ifstream &in) {
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        T m;
        getline(ss, m.ID, ';');
        getline(ss, m.userName, ';');
        getline(ss, m.password, ';');
        getline(ss, m.fullName, ';');
        getline(ss, m.phoneNumber, ';');
        getline(ss, m.dateOfBirth, ';');
        getline(ss, m.gender, ';');
        list.push_back(m);
    }
}

void readFileManagement(int i, DoubleLinkedList<Admin> &adminList, DoubleLinkedList<Staff> &staffList, DoubleLinkedList<Customer> &customerList) {
    ifstream in;
    
    if (i == 1) {
        in.open("../../TEXT/AdminList.txt");
        if (!in.is_open()) {
            throw runtime_error("Error opening file");
        }
        getInf<Admin>(adminList, in);
    } 
    else if (i == 2) {
        in.open("../../TEXT/StaffList.txt");
        if (!in.is_open()) {
            throw runtime_error("Error opening file");
        }
        getInf<Staff>(staffList, in);
    } 
    else if (i == 3) {
        cout<<"Ban khong co quyen truy cap"<<endl;
        // in.open("../../TEXT/CustomerList.txt");
        // if (!in.is_open()) {
        //     throw runtime_error("Error opening file");
        // }
        // getInf<Customer>(customerList, in);
    }
    in.close();
}

void logIn() {
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
    cout << "Nhap mat khau: ";
    cin >> password;

    DoubleLinkedList<Admin> adminList;
    DoubleLinkedList<Staff> staffList;
    DoubleLinkedList<Customer> customerList;

    // Đọc danh sách người dùng
    readFileManagement(1, adminList, staffList, customerList); // Đọc Admin
    bool loggedIn = false;

    // Kiểm tra thông tin đăng nhập
    if (choice == 1) { // Admin
        for (int i=0; i<adminList.getSize(); i++) {
            if (adminList[i].userName == userName && adminList[i].password == password) {
                cout << "Dang nhap thanh cong cho Admin: " << endl;
                loggedIn = true;
                break;
            }
        }
    } 
    else if (choice == 2) { // Staff
        for (int i=0; i<staffList.getSize(); i++) {
            if (staffList[i].userName == userName && staffList[i].password == password) {
                cout << "Dang nhap thanh cong cho Staff "<< endl;
                loggedIn = true;
                break;
            }
        }
    } 
    else if (choice == 3) { // Customer
        // for (int i=0; i<customerList.getSize(); i++) {
        //     if (customerList[i].username == userName && customerList[i].password == password) {
        //         cout << "Dang nhap thanh cong cho Customer: " << customer.fullName << endl;
        //         loggedIn = true;
        //         break;
        //     }
        // }
    }

    if (!loggedIn) {
        cout << "Ten dang nhap hoac mat khau khong chinh xac." << endl;
    }
}
