#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "screening.cpp"
#include "customer.h"
#include "regularCustomer.h"
#include "../Template/DoubleLinkedList.h"
using namespace std;

class Ticket {
private:
    int ID;
    float price;
    Screening screening;
    Hall seat;
    Customer* customer=nullptr;
    static int count;

public:
    Ticket();
    Ticket(int ID, float price, const Screening& screening, const Hall& seat, const Customer& customer);
    ~Ticket();

    
    void setID(int ID);
    void setPrice(float price);
    void setScreening(const Screening& screening);
    void setSeat(const Hall& seat);

    int getID() const;
    float getPrice() const;
    Screening getScreening() const;
    Hall getSeat() const;

    
    void sellTicket();
    void saveToFile();

    friend ostream& operator<<(ostream& output, const Ticket& t);
};
int Ticket::count=0;
#endif // TICKET_H