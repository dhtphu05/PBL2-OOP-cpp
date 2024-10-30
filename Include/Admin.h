#include "User.h"
#include"Staff.h"

#ifndef ADMIN_H
#define ADMIN_H
class Admin:public Staff{
    // string IDAdmin;
    public:
    Admin();
    Admin(string &ID,string &userName, string&, string &fullName, string &email, string &phoneNumber, string &gender, string &password);
    void addStaff();
    void editStaff();
    void removeStaff();
    void showStaff();
    void savetoFile();
    void readfromFile();
    void saveAgainFile(DoubleLinkedList<Staff>&);
    friend void logIn();
    // template <class T>
    // friend void getInf(DoubleLinkedList<T> &list, ifstream &in););
};
#endif