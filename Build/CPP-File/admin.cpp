#include"../../Include/Admin.h"
Admin::Admin()
{
    this->ID=count;
    count++;
}
Admin::Admin(string &userName, string&password, string &fullName, string &phoneNumber,string &DOB, string &gender)
    : Staff(userName,password,fullName,phoneNumber, DOB, gender)
    {
        
    }
void Admin::addStaff(){

}
void Admin::editStaff(){

}
void Admin::removeStaff(){

}
void Admin::showStaff(){

}
void Admin::savetoFile(){

}
void Admin::readfromFile(){

}
void Admin::saveAgainFile(DoubleLinkedList<Staff>&){

}

