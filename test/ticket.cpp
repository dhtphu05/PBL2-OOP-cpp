#include "Ticket.h"
#include "customer.h"
#include "regularCustomer.cpp"

Ticket::Ticket() : ID(count+1), price(60000.0), customer {nullptr} {}

Ticket::Ticket(int ID, float price, const Screening& screening, const Hall& seat, const Customer& customer)
    : ID(ID), price(price), screening(screening), seat(seat) {}

Ticket::~Ticket(){
    delete customer;
}
void Ticket::setID(int ID) {
    this->ID = ID;
}

int Ticket::getID() const {
    return ID;
}

void Ticket::setPrice(float price) {
    this->price = price;
}

float Ticket::getPrice() const {
    return price;
}

void Ticket::setScreening(const Screening& screening) {
    this->screening = screening;
}

Screening Ticket::getScreening() const {
    return screening;
}

void Ticket::setSeat(const Hall& seat) {
    this->seat = seat;
}

Hall Ticket::getSeat() const {
    return seat;
}


void Ticket::sellTicket() {
    ID=count+1;

    screening=Screening::selectScreening();
    if (screening.getId()==0){
        sellTicket();
    }
    int option;

    do { 
        cout<<"\n1. Khach hang thuong \n2.Khach hang vip \n";
        cin>>option;
        option=1;
        cin.ignore();
        if (option==1){
            Customer* customer = new RegularCustomer();

    // Gọi phương thức addCustomer của lớp RegularCustomer
    customer->addCustomer();  // Output: "Adding a regular customer."
        }
        else {
            cout<<"Lua chon loi, moi ban nhap lai!!!";
        } 
    }while(option!=1 );

    int seatno;
    cout<<"\nChon ghe (VD: 23, 12): ";
    cin>>seatno;
    screening.allotHall(seat); 
    seat.setSeat(seatno); 
    cout<<"\nGia ve la: "<<price<<endl;
    cout<<"Xac nhan da thanh toan ? \n1.Da thanh toan \n2.Chua thanh toan\n";
    int opt;
    do{

    cin>>opt;
    switch (opt)
    {
    case 1:
    cout << "Da ban ve. So ghe: " << seatno << endl;
        saveToFile();
        count++;
        break;
    case 2:    
        cout<<"Transaction Discarded."<<endl;
        break;
    default:
        cout<<"Invalid option! ";
        break;
    }
    }while (opt!=1 && opt!=2);
}


void Ticket::saveToFile() {
    ofstream fout;
    try{
    fout.open("tickets.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening screenings.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    fout<<ID<<endl;
    fout<<price<<endl;
    fout<<getScreening()<<endl;
    fout.close();
    cout << "Da luu giao dich!" << endl;
}
