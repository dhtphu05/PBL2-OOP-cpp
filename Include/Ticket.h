#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include "../Template/DoubleLinkedList.h"
// #include "User.h"
#include "Show.h"
#include "Movie.h"
using namespace std;

class Ticket{
    int ID_Ticket;
    Movie movie;
    //Seat seat;
    double price;
    string createdOn;
    public:
    Ticket(int ID_Ticket, Movie movie,  double price, string createdOn) : ID_Ticket(ID_Ticket), movie(movie), price(price), createdOn(createdOn) {}
    ~Ticket(){}
    //getter
    int getID_Ticket() const;
    Movie getMovie() const;
    //Seat getSeat() const;
    double getPrice() const;
    string getCreatedOn() const;
    //setter
    void setID_Ticket(int ID_Ticket);
    void setMovie(Movie movie);
    //void setSeat(Seat seat);
    void setPrice(double price);
    void setCreatedOn(string createdOn);
    
    //method
    void addTicket(const Ticket& ticket);
    void viewTicket(DoubleLinkedList<Ticket>& tickets);
    void deleteTicket( Ticket& ticket);
    //Ticket searchTicket();
    void updateTicket( Ticket& ticket);
    
};