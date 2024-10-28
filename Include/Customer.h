#include"User.h"
class Customer : User
{
protected:
    string IDCustomer;
    string user;
public:
    Customer(string user = "staff"):user(user){};
    Customer(string, int , string ,string, string, string);
    
    void makePayment();
    void bookTicket();
};
