#ifndef HALL_H
#define HALL_H

#include <iostream>
#include "../Template/DoubleLinkedList.h"
#include<fstream>
#include "seat.cpp"

using namespace std;

class Hall {
private:
    int number;
    int capacity;
    bool is3DCapable;
    static int count;
    Seat *seats;

    bool saveToFile();
public:
    Hall();
    Hall(int number, int capacity, bool is3DCapable);
    ~Hall();

    // Getter and setter methods
    void setNumber(int number);
    int getNumber() const;
    void setCapacity(int capacity);
    int getCapacity() const;
    void set3DCapable(bool is3DCapable);
    bool get3DCapable() const;
    void setSeats(int cap);

    // Methods
    void addHall();
    static Hall selectHall();
    static void viewHalls(const DoubleLinkedList<Hall>& halls);
    static void editHall(DoubleLinkedList<Hall>& halls);
    static void readFile(DoubleLinkedList<Hall>&halls);
    std::string getHall() const;
    void setSeat(int seatno);

};
int Hall::count=0;
#endif
