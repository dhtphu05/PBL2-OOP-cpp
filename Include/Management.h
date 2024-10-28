#include"User.h"
#include"../Template/DoubleLinkedList.h"
class Management{
    public:
    void addMovie(DoubleLinkedList<Movie> &);
    void editMovie(DoubleLinkedList<Movie> &);
    void removeMovie(Movie);
    void showMovie(DoubleLinkedList<Movie> &);
    void showCustomer(Customer);
    void bookTicket();
    void cancelBooking();
    void makePayment();
    void handlePayment();
};
