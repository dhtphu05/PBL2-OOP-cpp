#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>
#include <fstream>
#include "../Template/DoubleLinkedList.h"

using namespace std;

class Customer {
protected:
    string name;
    int age;
    string contactInfo;

public:
    Customer() : name(""), age(0), contactInfo("") {}

    Customer(const string& name, int age, const string& contactInfo)
        : name(name), age(age), contactInfo(contactInfo) {}


    void setName(const string& name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setContactInfo(const string& contactInfo) {
        this->contactInfo = contactInfo;
    }

    string getName() const {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getContactInfo() const {
        return contactInfo;
    }

    virtual void addCustomer(){};
    string getCustomer(){
        string line="";
        line+="Name: "+name+"\nAge: "+to_string(age)+"\nContact: "+contactInfo;
        return line;
    }

};

#endif