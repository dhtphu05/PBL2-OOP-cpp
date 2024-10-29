#include <windows.h>
#include "Movie.cpp"
#include "User.cpp"
// #include <windows.h>
int main()
{
label_1:
    menuStaff();
    Movie movie;
    int choice;
    cout << "Nhap lua chon: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        movie.addMovie();
        cout << "Them phim thanh cong";
        Sleep(4);
        system("cls");
        goto label_1;
        break;
    case 2:
        movie.editMovie();
        cout << "Sua phim thanh cong";
        // system("cls");
        goto label_1;
        break;
    case 3:
        movie.removeMovie();
        cout << "Xoa phim thanh cong";
        Sleep(2000);
        system("cls");
        goto label_1;
        break;
    case 4:
        system("cls");
        movie.show();
        // Sleep(2000);
        // system("cls");
        goto label_1;
        break;
    case 5:
        system("cls");
        movie.searchMovie();
        goto label_1;
        break;
    case 6:
        // bookTicket();
        break;
    case 7:
        // cancelBooking();
        break;
    case 8:
        // makePayment();
        break;
    case 9:
        // handlePayment();
        break;
    default:
        cout << "lua chon khong hop le" << endl;
        break;
    }
}