#include "movie.h"
#include <iomanip>

Movie::Movie() : duration(0) {
}

Movie::Movie(const string& title, const string& genre, int duration, const string& releaseDate, const int& ageRating, int count)
    : title(title), genre(genre), duration(duration), releaseDate(releaseDate), ageRating(ageRating) {}

void Movie::setTitle(const string& title) {
    this->title = title;
}

string Movie::getTitle() const {
    return title;
}

void Movie::setGenre(const string& genre) {
    this->genre = genre;
}

string Movie::getGenre() const {
    return genre;
}

void Movie::setDuration(int duration) {
    this->duration = duration;
}

int Movie::getDuration() const {
    return duration;
}

void Movie::setReleaseDate(const string& releaseDate) {
    this->releaseDate = releaseDate;
}

string Movie::getReleaseDate() const {
    return releaseDate;
}

void Movie::setAgeRating(const int& ageRating) {
    this->ageRating = ageRating;
}

int Movie::getAgeRating() const {
    return ageRating;
}

void Movie::setCount(int count) {
    this->count = count;
}

int Movie::getCount() const {
    return count;
}

void Movie::viewMovie(const DoubleLinkedList<Movie>& movies) {
    if (movies.isEmpty()) {
        cout << "Khong co phim de hien thi" << std::endl;
        return;
    }

    cout << "Danh sach phim:" << endl;
    cout<<setw(20)<<left<<"Ten"<<setw(20)<<left<<"Chu de"<<setw(20)<<left<<"Thoi luong"<<setw(20)<<left<<"Thoi diem ra mat"<<setw(20)<<left<<"Age Rating"<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    for (int i = 0; i < movies.getSize(); i++) {
        cout << movies[i]<<endl; 
    }
}



void Movie::overwriteFile(DoubleLinkedList<Movie>& movies){
    ofstream fout;
    try{
    fout.open("movies.txt");
    if (fout.fail()){
        throw runtime_error("Error opening movies.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
     for (int i = 0; i < movies.getSize(); i++) {
        fout<<movies[i].title<<endl;
        fout<<movies[i].genre<<endl;
        fout<<movies[i].duration<<endl;
        fout<<movies[i].releaseDate<<endl;
        fout<<movies[i].ageRating<<endl;
    }
    fout.close();

}

bool Movie::saveToFile() {
    ofstream fout;
    try{
    fout.open("movies.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening movies.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout<<title<<endl;
    fout<<genre<<endl;
    fout<<duration<<endl;
    fout<<releaseDate<<endl;
    fout<<ageRating<<endl;
    fout.close();
    return true;
}

void Movie::readFile(DoubleLinkedList<Movie>& movies) {
    ifstream fin;
    Movie m;
    try{
    fin.open("movies.txt");
    if (fin.fail()){
        throw runtime_error("Error opening movies.txt for reading");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    while( getline(fin,m.title)){
        getline(fin,m.genre);
        fin>>m.duration;
        fin.get();
        getline(fin,m.releaseDate);
        fin>>m.ageRating;
        fin.get();
        movies.push_back(m);
        count++;
    }
}

ostream& operator<<(ostream& output, const Movie& movie) {
    output<<setw(20)<<left<<movie.title<<setw(20)<<left<<movie.genre<<setw(20)<<left<<movie.duration<<setw(20)<<left<<movie.releaseDate<<movie.ageRating;
    return output;
}


string Movie:: getMovie() const{
    string line="";
    line+=title+"\n"+genre+"\n"+to_string(duration)+"\n"+releaseDate+"\n"+to_string(ageRating);
    return line;
}
