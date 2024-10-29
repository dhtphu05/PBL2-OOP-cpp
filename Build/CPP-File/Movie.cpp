#include "../../Include/Movie.h"
#include "../../Template/DoubleLinkedList.h"
#include <fstream>
#include <sstream>
#include "menu.cpp"
#include <cctype>
Movie::Movie()
{
}
Movie::Movie(const string &title, const string &genre, string &duration, const string &releaseDate, const string &Rating, string &director, string &actor, string &country, string &decription)
    : title(title), genre(genre), duration(duration), releaseDate(releaseDate), rating(Rating), director(director), actor(actor), country(country), description(description)
{
}
void Movie::addMovie()
{
    Movie newMovie;
    cin >> newMovie;
    newMovie.saveToFile(0);
}
void subEditMovie(Movie &movie, string &line, string message)
{
    cout << message << " moi: " << endl;
    cin.ignore();
    getline(cin, line);
}
void subSaveAgainFile(DoubleLinkedList<Movie> &movieList)
{
    ofstream out;
    out.open("../../TEXT/MovieList.txt");
    if (!out.is_open())
    {
        throw runtime_error("Error opening file");
    }
    for (int i = 0; i < movieList.getSize(); i++)
    {
        out << movieList[i].ID_Movie << ";" << movieList[i].title << ";" << movieList[i].genre << ";" << movieList[i].duration << ";" << movieList[i].releaseDate << ";" << movieList[i].director << ";" << movieList[i].actor << ";" << movieList[i].country << ";" << movieList[i].description << ";" << movieList[i].rating << endl;
    }
}
void Movie::editMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    system("cls");
    cout << "Nhap ID phim can sua: ";
    string ID;
    cin >> ID;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            menuEditFilm();
            cout << "Chon thong tin sua  " << endl;
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                subEditMovie(movieList[i], movieList[i].ID_Movie, "ID");
                break;
            case 2:
                subEditMovie(movieList[i], movieList[i].title, "Ten phim");
                break;
            case 3:
                subEditMovie(movieList[i], movieList[i].genre, "The Loai");
                break;
            case 4:
                subEditMovie(movieList[i], movieList[i].duration, "Thoi luong");
                break;
            case 5:
                subEditMovie(movieList[i], movieList[i].releaseDate, "Ngay san xuat");
                break;
            case 6:
                subEditMovie(movieList[i], movieList[i].director, "Dao dien");
                break;
            case 7:
                subEditMovie(movieList[i], movieList[i].actor, "Dien vien");
                break;
            case 8:
                subEditMovie(movieList[i], movieList[i].country, "Nuoc san xuat");
                break;
            case 9:
                subEditMovie(movieList[i], movieList[i].description, "Mo ta");
                break;
            case 10:
                subEditMovie(movieList[i], movieList[i].rating, "Rating");
                break;
            }
        }
    }
    subSaveAgainFile(movieList);
}
void Movie::saveToFile(int i)
{
    ofstream out;
    if (i)
    {
        out.open("../../TEXT/MovieList.txt");
    }
    else
    {
        out.open("../../TEXT/MovieList.txt", std::ios::app);
    }
    if (!out.is_open())
    {
        throw runtime_error("Khong the mo file");
    }
    out << this->ID_Movie << ";" << this->title << ";"
        << this->genre << ";" << this->duration << ";"
        << this->releaseDate << ";" << this->director << ";"
        << this->actor << ";" << this->country << ";"
        << this->description << ";" << this->rating << endl;
    out.close();
}
istream &operator>>(istream &in, Movie &m)
{
    cout << "ID: ";
    in >> m.ID_Movie;
    cout << "Ten phim: ";
    in.ignore();
    getline(in, m.title);
    cout << "The loai: ";
    getline(in, m.genre);
    cout << "Thoi luong: ";
    getline(in, m.duration);
    cout << "Ngay phat hanh: ";
    getline(in, m.releaseDate);
    cout << "Dao dien: ";
    getline(in, m.director);
    cout << "Dien vien: ";
    getline(in, m.actor);
    cout << "Nuoc san xuat:";
    getline(in, m.country);
    cout << "Mo ta: ";
    getline(in, m.description);
    cout << "Rating: ";
    getline(in, m.rating);
    return in;
}
ostream &operator<<(ostream &out, const Movie &m)
{
    out << "ID: " << m.ID_Movie << endl;
    out << "Ten phim: " << m.title << endl;
    out << "The loai: " << m.genre << endl;
    out << "Thoi luong: " << m.duration << endl;
    out << "Ngay phat hanh: " << m.releaseDate << endl;
    out << "Dao dien: " << m.director << endl;
    out << "Dien vien: " << m.actor << endl;
    out << "Nuoc san xuat: " << m.country << endl;
    out << "Mo ta: " << m.description << endl;
    out << "Rating: " << m.rating << endl;
    return out;
}
void Movie::removeMovie()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    string ID;
    cout << "Nhap ID phim can xoa: ";
    cin >> ID;
    for (int i = 0; i < movieList.getSize(); i++)
    {
        if (movieList[i].ID_Movie == ID)
        {
            movieList.earse(i);
        }
    }
    subSaveAgainFile(movieList);
}
void Movie::readFile(DoubleLinkedList<Movie> &movieList)
{

    ifstream in;
    in.open("../../TEXT/MovieList.txt");
    if (!in.is_open())
    {
        throw runtime_error("Error opening file");
    }
    string line, ss;
    while (getline(in, line))
    {
        Movie m;
        stringstream ss(line);
        getline(ss, m.ID_Movie, ';');
        getline(ss, m.title, ';');
        getline(ss, m.genre, ';');
        getline(ss, m.duration, ';');
        getline(ss, m.releaseDate, ';');
        getline(ss, m.director, ';');
        getline(ss, m.actor, ';');
        getline(ss, m.country, ';');
        getline(ss, m.description, ';');
        getline(ss, m.rating);
        movieList.push_back(m);
    }
    in.close();
}
void Movie::Display()
{
    cout << *this;
}
void Movie::show()
{
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    movieList.display();
}
std::string toLowerCase(const std::string &str)
{
    std::string result = str;
    for (char &c : result)
    {
        c = std::tolower(c); // Chuyển từng ký tự sang chữ thường
    }
    return result;
}
void Movie::searchMovie()
{
    int count = false;
    DoubleLinkedList<Movie> movieList;
    this->readFile(movieList);
    string title;
    cout << "Nhap ten phim can tim: ";
    cin.ignore();
    getline(cin, title);
    title = toLowerCase(title);
    for (int i = 0; i < movieList.getSize(); i++)
    {

        if (toLowerCase(movieList[i].title) == title)
        {
            count = true;
            cout << movieList[i];
            break;
        }
    }
    if (count == false)
    {
        cout << "Khong tim thay phim" << endl;
    }
}
