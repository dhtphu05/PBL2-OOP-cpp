#include "Movie.h"
#include "../Template/DoubleLinkedList.h"
#include <iostream>
using namespace std;
#ifndef USER_H
#define USER_H

class User
{
public:
    string fullName;
    string dateOfBirth;
    string email;
    string phoneNumber;
    string gender;

public:
    User();
    User(string &, string &, string &, string &, string &);
    void setFullName(string &);
    void setAge(string &);
    void setDOB(string &);
    void setGender(string &);
    void setEmail(string &);
    void setPhoneNumber(string &);
    void setUserName(string &);
    void resetPassword(string &);
    string getID() const;
    string getDOB() const;
    string getFullName() const;
    int getAge() const;
    string getGender() const;
    string getEmail() const;
    string getPhoneNumber() const;
    string getUserName() const;
    string getPassword() const;
    virtual void savetoFile();
    virtual void readfromFile();
    virtual void saveAgainFile();
};

// class Management
// {
// public:
//     void addMovie(DoubleLinkedList<Movie> &);
//     void editMovie(DoubleLinkedList<Movie> &);
//     void removeMovie(Movie);
//     void showMovie(DoubleLinkedList<Movie> &);
//     void showCustomer(Customer);
//     void bookTicket();
//     void cancelBooking();
//     void makePayment();
//     void handlePayment();
// };

// class Staff : public Person, public Management
// {
// protected:
//     int IDStaff;
// };
// class Admin : public Person, public Management
// {
// private:
//     int IDAdmin;

// public:
//     void addStaff();
//     void removeStaff();
//     void editStaff();
//     void getRevenueReport();
// };
#endif