
#include "User.h"
#include"Customer.h"
#include<iostream>
using namespace std;
#ifndef STAFF_H
#define STAFF_H
class Staff:public User{
    public:
    string ID;
    string userName;
    string password;
    public:
    Staff();
    Staff(string &ID,string &userName, string&, string &fullName, string &email, string &phoneNumber, string &gender, string &password);
    void addCustomer();
    void editCustomer();
    void removeCustomer();
    void showCustomer();
    void savetoFile();
    void readfromFile();
    void saveAgainFile(DoubleLinkedList<Customer>&);
    string getID() {
        return ID;
    };
    string getUserName() const{
        return userName;
    };
    string getPassword() const{
        return password;
    };
    void setID(string &ID){
        this->ID=ID;
    };
    void setUserName(string &userName){
        this->userName=userName;
    };
    void setPassword(string &password){
        this->password=password;
    };

};
#endif