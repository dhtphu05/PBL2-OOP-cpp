#include "hall.h"

Hall::Hall() : number(0), capacity(0), is3DCapable(false), seats(nullptr) {}

Hall::Hall(int number, int capacity, bool is3DCapable)
    : number(number), capacity(capacity), is3DCapable(is3DCapable) {
        seats = new Seat[capacity];
    }

Hall:: ~Hall(){
    delete[]seats;
}
void Hall::setNumber(int number)
{
    this->number = number;
}

int Hall::getNumber() const
{
    return number;
}

void Hall::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Hall::getCapacity() const
{
    return capacity;
}

void Hall::set3DCapable(bool is3DCapable)
{
    this->is3DCapable = is3DCapable;
}

bool Hall::get3DCapable() const
{
    return is3DCapable;
}

void Hall::setSeats(int cap) {
    seats=new Seat[cap];
}



bool Hall::saveToFile()
{
    ofstream fout;
    try
    {
        fout.open("halls.txt", ios::app);
        if (fout.fail())
        {
            throw runtime_error("Error opening halls.txt for writing");
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        return false;
    }
    fout << number << " " << capacity << " " << is3DCapable << endl;
    fout.close();
    return true;
}

void Hall::readFile(DoubleLinkedList<Hall> &halls)
{
    ifstream fin;
    try
    {
        fin.open("halls.txt");
        if (fin.fail())
        {
            throw runtime_error("Error opening halls.txt for reading");
        }
    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
        return;
    }
    Hall h;
    while (fin >> h.number >> h.capacity >> h.is3DCapable)
    {
        halls.push_back(h);
        count++;
    }
    fin.close();
}

string Hall:: getHall() const{
    string line="";
    line=to_string(number)+"\n"+to_string(capacity)+to_string(is3DCapable);
    return line;
}

void Hall:: setSeat(int seatno){
    const int seatsPerRow = 10;
    if(!seats[seatno].getisTaken()){
        seats[seatno].setisTaken(true);
        int columnNumber = (seatno% seatsPerRow); 
        int rowNumber = (seatno / seatsPerRow); 
        cout<<"Ghe #"<<seatno<<" o hang : "<<rowNumber<<" Cot: "<<columnNumber<<endl;
    }
    else {
        cout<<"Ghe# "<<seatno<<" da duoc dat cho truoc. "<<endl;
    }
}


