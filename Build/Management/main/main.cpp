#include "../Management.cpp"
#include <iostream>
using namespace std;
int main()
{
    int count = 0;
    Staff staff;
    DoubleLinkedList<Movie> listFilm;
    while (count < 5)
    {
        staff.addMovie(listFilm);
        count++;
    }
    staff.showMovie(listFilm);
}