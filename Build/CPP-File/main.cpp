#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <windows.h>
#include "Movie.cpp"
#include "User.cpp"
#include "Staff.cpp"
#include "customer.cpp"
#include "admin.cpp"
#include"../login/login.cpp"

void displayMenu()
{
    menuStaff();
}

int main()
{
    bool loggedIn = false;
    while (!loggedIn)
    {
        logIn();
        cout << "Dang nhap thanh cong!" << endl;
        loggedIn = true; 
        Sleep(2000); 

    Movie movie;
    Staff staff;
    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        cout << "Nhap lua chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            movie.addMovie();
            cout << "Them phim thanh cong!";
            Sleep(2000);
            system("cls");
            break;
        case 2:
            movie.editMovie();
            cout << "Sua phim thanh cong!";
            Sleep(2000);
            system("cls");
            break;
        case 3:
            movie.removeMovie();
            cout << "Xoa phim thanh cong!";
            Sleep(2000);
            system("cls");
            break;
        case 4:
            movie.show();
            Sleep(2000);
            system("cls");
            break;
        case 5:
            movie.searchMovie();
            Sleep(2000);
            system("cls");
            break;
        case 6:
            staff.addCustomer();
            cout << "Them khach hang thanh cong!";
            Sleep(2000);
            system("cls");
            break;
        case 7:
            staff.showCustomer();
            Sleep(2000);
            system("cls");
            break;
        case 8:
            staff.editCustomer();
            Sleep(2000);
            system("cls");
            break;
        case 9:
            cout << "Dang xuat...";
            loggedIn = false;
            Sleep(2000);
            system("cls");
            main(); // Gọi lại main để đăng nhập lại
            return 0; 
        default:
            cout << "Lua chon khong hop le!" << endl;
            Sleep(2000);
            system("cls");
            break;
        }
    }

    return 0;
    }
}
