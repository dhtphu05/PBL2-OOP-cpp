#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "../Template/DoubleLinkedList.h"
#include "Show.h"
using namespace std;



class Movie{
    private:
    int ID_Movie;
    string title;
    string genre;
    string releaseDate;
    string director;
    string rating;
    string duration;
    string actor;
    string language;
    string description;
    DoubleLinkedList<Show> shows;
    public:
    Movie();
    Movie(int ID_Movie, string title, string genre, string releaseDate, string director, string rating, string duration, string actor, string language, string description);
    //getter
    string getID_Movie();
    string getTitle();
    string getGenre();
    string getReleaseDate();
    string getDirector();
    string getRating();
    string getDuration();
    string getActor();
    string getLanguage();
    string getDescription();
    //setter
    void setID_Movie(string ID_Movie);
    void setTitle(string title);
    void setGenre(string genre);
    void setReleaseDate(string releaseDate);
    void setDirector(string director);
    void setRating(string rating);
    void setDuration(string duration);
    void setActor(string actor);
    void setLanguage(string language);
    void setDescription(string description);
    //print
    //destructor
    ~Movie();

    void addMovie();
    void editMovie();
    void deleteMovie();
    void searchMovie();
    void showMovie();
    void getMovie();





};