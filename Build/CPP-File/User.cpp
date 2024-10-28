#include"../../Include/User.h"
#include <fstream>
User::User(){

}
User::User(string &name, int &age, string &gender, string &email, string &phoneNumber, string &userName, string &password)
:fullName(name),age(age),gender(gender), email(email),phoneNumber(phoneNumber), userName(userName), password(password)
{
    ofstream fileUserList, fileUserLogIn;
    fileUserList.open("../../TEXT/UserList.txt", ios::app);
    fileUserLogIn.open("../../TEXT/UserLogIn.txt", ios::app);
    fileUserList<<fullName<<";"<<age<<";"<<gender<<";"<<email<<";"<<phoneNumber<<endl;
    fileUserLogIn<<userName<<";"<<password<<endl;
    fileUserList.close();
    fileUserLogIn.close();
}
void User::setFullName(string&fullName){
    DoubleLinkedList<User> userList;
    ifstream fileUserList;
    fileUserList.open("../../TEXT/UserList.txt");
    
    this->fullName=fullName;
}
void User::setAge(int &age){
    this->age = age;
}
void User::setGender(string &gender){
    this->gender= gender;
}
void User::setEmail(string &email){
    this->email=email;
}
void User::setPhoneNumber(string &phoneNumber){
    this->phoneNumber = phoneNumber;
}
void User::setUserName(string &username){
    this->userName = username;
}
void User::resetPassword(string& password){
    this->password= password;
}
string User::getFullName() const{
    return this->fullName;
}
int User::getAge() const{
    return this->age;
}
string User::getGender()const{
    return this->gender;
} 
string User::getEmail() const{
    return this->email;
}
string User::getPhoneNumber() const{
    return this->phoneNumber;
}
string User::getUserName()const{
    return this->userName;
}
string User::getPassword()const{
    return this->password;
}