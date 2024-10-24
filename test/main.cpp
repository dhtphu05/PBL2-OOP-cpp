#include "ticket.cpp"

using namespace std;

void displayMainMenu() {
    cout << "\n--------------------He thong quan ly rap chieu phim--------------------\n" << endl;
    cout << "1. Quan ly phim" << endl;
    cout << "2. Quan ly suat chieu" << endl;
    cout << "3. Quan ly phong chieu" << endl;
    cout << "4. Mua / Ban ve xem phim" << endl;
    cout << "5. Quan ly khach hang" << endl;
    cout << "6. Exit" << endl;
    cout << "Nhap lua chon cua ban: ";
}




void ticketManagementMenu(DoubleLinkedList<Ticket> &tickets) {
    Ticket t;
    cout << "\nMenu ban ve\n" << endl;
    cout <<"1. Ban ve \n2. Hoan ve "<<endl;
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            t.sellTicket();
            tickets.push_back(t);
            break;
        
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
    }
}

void loadData(DoubleLinkedList <Movie> &movies, DoubleLinkedList <Screening> &screenings, DoubleLinkedList <Hall> &halls, DoubleLinkedList <Ticket> &tickets){
    Movie::readFile(movies);
    Screening::readFile(screenings);
    Hall::readFile(halls);
}
int main() {
    DoubleLinkedList<Movie> movies;
    DoubleLinkedList<Screening> screenings;
    DoubleLinkedList<Hall> halls;
    DoubleLinkedList<Ticket> tickets;
    loadData(movies, screenings, halls, tickets);
    while (true) {
        displayMainMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 4:
                ticketManagementMenu(tickets);
                break;
            
            case 6:
                cout << "Thoat chuong trinh" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le! Vui long chi chon tu 1 den 6" << endl;
        }
    }
    return 0;
}
