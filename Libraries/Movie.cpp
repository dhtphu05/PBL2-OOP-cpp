#include "../Include/Movie.h"
#include <fstream>

Movie::Movie(){
    this->ID_Movie=0;
    this->title="";
    this->genre="";
    this->releaseDate="";
    this->director="";
    this->rating="";
    this->duration="";
    this->actor="";
    this->language="";
    this->description="";
}
Movie::Movie(int ID_Movie, string title, string genre, string releaseDate, string director, string rating, string duration, string actor, string language, string description){
    this->ID_Movie=ID_Movie;
    this->title=title;
    this->genre=genre;
    this->releaseDate=releaseDate;
    this->director=director;
    this->rating=rating;
    this->duration=duration;
    this->actor=actor;
    this->language=language;
    this->description=description;
}
string Movie::getID_Movie(){
    return to_string(this->ID_Movie);
}
string Movie::getTitle(){
    return this->title;
}
string Movie::getGenre(){
    return this->genre;
}
string Movie::getReleaseDate(){
    return this->releaseDate;
}
string Movie::getDirector(){
    return this->director;
}
string Movie::getRating(){
    return this->rating;
}
string Movie::getDuration(){
    return this->duration;
}
string Movie::getActor(){
    return this->actor;
}
string Movie::getLanguage(){
    return this->language;
}
string Movie::getDescription(){
    return this->description;
}
void Movie::setID_Movie(string ID_Movie){
    this->ID_Movie=stoi(ID_Movie);
}
void Movie::setTitle(string title){
    this->title=title;
}
void Movie::setGenre(string genre){
    this->genre=genre;
}
void Movie::setReleaseDate(string releaseDate){
    this->releaseDate=releaseDate;
}
void Movie::setDirector(string director){
    this->director=director;
}
void Movie::setRating(string rating){
    this->rating=rating;
}
void Movie::setDuration(string duration){
    this->duration=duration;
}
void Movie::setActor(string actor){
    this->actor=actor;
}
void Movie::setLanguage(string language){
    this->language=language;
}
void Movie::setDescription(string description){
    this->description=description;
}
void Movie::showMovie(){
    cout<<"ID_Movie: "<<this->ID_Movie<<endl;
    cout<<"Tiêu đề: "<<this->title<<endl;
    cout<<"Thể loại: "<<this->genre<<endl;
    cout<<"Ngày phát hành: "<<this->releaseDate<<endl;
    cout<<"Đạo diễn: "<<this->director<<endl;
    cout<<"Đánh giá: "<<this->rating<<endl;
    cout<<"Thời lượng: "<<this->duration<<endl;
    cout<<"Diễn viên: "<<this->actor<<endl;
    cout<<"Ngôn ngữ: "<<this->language<<endl;
    cout<<"Mô tả: "<<this->description<<endl;
}
Movie::~Movie(){
    
}
void Movie::addMovie(){
    ofstream outputFile("movie.txt", ios::app);
    cout<<"Nhập ID_Movie: ";
    cin>>this->ID_Movie;
    cout<<"Nhập tiêu đề: ";
    cin.ignore();
    getline(cin, this->title);
    cout<<"Nhập thể loại: ";
    getline(cin, this->genre);
    cout<<"Nhập ngày phát hành: ";
    getline(cin, this->releaseDate);
    cout<<"Nhập đạo diễn: ";
    getline(cin, this->director);
    cout<<"Nhập đánh giá: ";
    getline(cin, this->rating);
    cout<<"Nhập thời lượng: ";
    getline(cin, this->duration);
    cout<<"Nhập diễn viên: ";
    getline(cin, this->actor);
    cout<<"Nhập ngôn ngữ: ";
    getline(cin, this->language);
    cout<<"Nhập mô tả: ";
    getline(cin, this->description);
    outputFile<<this->ID_Movie<<endl;
    outputFile<<this->title<<endl;
    outputFile<<this->genre<<endl;
    outputFile<<this->releaseDate<<endl;
    outputFile<<this->director<<endl;
    outputFile<<this->rating<<endl;
    outputFile<<this->duration<<endl;
    outputFile<<this->actor<<endl;
    outputFile<<this->language<<endl;
    outputFile<<this->description<<endl;
    outputFile.close();
}
