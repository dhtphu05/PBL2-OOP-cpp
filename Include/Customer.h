#include "User.h"
#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer : public User
{
public:
    string ID;

public:
    Customer();
    Customer(string &ID, string &, string &, string &, string &, string &);
    void makePayment();
    void bookTicket();
    void savetoFile();
    void readfromFile(DoubleLinkedList<Customer> &);
    void saveAgainFile(DoubleLinkedList<Customer> &);
    void Display();
    string getID() const
    {
        return ID;
    };
    friend istream &operator>>(istream &in, Customer &customer);
    friend ostream &operator<<(ostream &out, Customer &customer);
};
#endif
