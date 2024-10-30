#include "../../Include/User.h"
#include <fstream>
User::User()
{
}
User::User(string &name, string &gender, string &email, string &datedob, string &phoneNumber)
    : fullName(name), dateOfBirth(datedob), gender(gender), email(email), phoneNumber(phoneNumber){
}
void User::setFullName(string &fullName)
{
    this->fullName = fullName;
}
// void User::setAge(int &age)
// {
//     this->age = age;
// }
void User::setGender(string &gender)
{
    this->gender = gender;
}
void User::setDOB(string &dateOfBirth)
{
    this->dateOfBirth = dateOfBirth;
}
void User::setEmail(string &email)
{
    this->email = email;
}
void User::setPhoneNumber(string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
// void User::setUserName(string &username)
// {
//     this->userName = username;
// }
// void User::resetPassword(string &password)
// {
//     this->password = password;
// }

string User::getFullName() const
{
    return this->fullName;
}
string User::getDOB() const
{
    return this->dateOfBirth;
}
string User::getGender() const
{
    return this->gender;
}
string User::getEmail() const
{
    return this->email;
}
string User::getPhoneNumber() const
{
    return this->phoneNumber;
}
// string User::getUserName() const
// {
//     return this->userName;
// }
// string User::getPassword() const
// {
//     return this->password;
// }
void User::savetoFile()
{
}
void User::readfromFile()
{
}
void User::saveAgainFile()
{
}