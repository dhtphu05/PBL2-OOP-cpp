#include "Screening.h"

Screening::Screening() {
    id=count+1;
}

Screening::Screening(const int&id, const string& startTime, const string& endTime, const string& date, Hall hallNumber, const bool& is3d, const Movie& movies)
    : id(id), startTime(startTime), endTime(endTime), date(date), hallNumber(hallNumber), is3d(is3d), movies(movies) {}

void Screening::setId(const int &id){
    this->id=id;
}
void Screening::setStartTime(const string& startTime) {
    this->startTime = startTime;
}

void Screening::setEndTime(const string& endTime) {
    this->endTime = endTime;
}

void Screening::setDate(const string& date) {
    this->date = date;
}

void Screening::setHallNumber(Hall hallNumber) {
    this->hallNumber = hallNumber;
}

void Screening::setIs3d(const bool& is3d) {
    this->is3d = is3d;
}

void Screening::setMovie(const Movie& movies) {
    this->movies = movies;
}
int Screening:: getId() const{
    return id;
}
string Screening::getStartTime() const {
    return startTime;
}

string Screening::getEndTime() const {
    return endTime;
}

string Screening::getDate() const {
    return date;
}

Hall Screening::getHallNumber() const {
    return hallNumber;
}

bool Screening::getIs3d() const {
    return is3d;
}

Movie Screening::getMovie() const {
    return movies;
}

void Screening::viewScreenings(const DoubleLinkedList<Screening>& screenings) {
    cout<<setw(10)<<left<<"ID"<<setw(20)<<left<<"Ten Phim"<<setw(20)<<left<<"Bat dau"<<setw(20)<<left<<"Ket thuc"<<setw(20)<<left<<"Ngay chieu"<<setw(20)<<left<<"Phong chieu"<<setw(20)<<left<<"Loai phong chieu"<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------"<<endl;
    for (int i=0; i<screenings.getSize(); i++){
        cout<<screenings[i]<<endl;
    }
}



bool Screening::overwriteFile(DoubleLinkedList<Screening> s){
    ofstream fout;
    try{
    fout.open("screenings.txt");
    if (fout.fail()){
        throw runtime_error("Error opening screenings.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    for (int i=0; i<s.getSize();i++){
        fout<<s[i].id<<endl;
        fout<<s[i].movies.getMovie()<<endl;
        fout<<s[i].startTime<<endl;
        fout<<s[i].endTime<<endl;
        fout<<s[i].date<<endl;
        fout<<s[i].hallNumber.getHall()<<endl;
        fout<<s[i].is3d<<endl;
    }
    fout.close();
    return true;

}
bool Screening::saveToFile() {
    ofstream fout;
    try{
    fout.open("screenings.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening screenings.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout<<id<<endl;
    fout<<movies.getMovie()<<endl;
    fout<<startTime<<endl;
    fout<<endTime<<endl;
    fout<<date<<endl;
    fout<<hallNumber.getHall()<<endl;
    fout<<is3d<<endl;
    fout.close();
    cout<<"Screening saved to file! "<<endl;
    return true;
}

void Screening::readFile(DoubleLinkedList<Screening>& screenings) {
    ifstream fin;
    Screening s;
    try{
    fin.open("screenings.txt");
    if (fin.fail()){
        throw runtime_error("Error opening screening.txt for reading");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    string title,genre,releaseDate;
    int duration,ageRating,number,capacity,type;
    while(fin>>s.id){
        fin.ignore();
        getline(fin,title);
        s.movies.setTitle(title);
        getline(fin,genre);
        s.movies.setGenre(genre);
        fin>>duration;
        s.movies.setDuration(duration);
        fin.ignore();
        getline(fin,releaseDate);
        s.movies.setReleaseDate(releaseDate);
        fin>>ageRating;
        fin.ignore();
        s.movies.setAgeRating(ageRating);
        getline(fin,s.startTime);
        getline(fin, s.endTime);
        getline(fin, s.date);
        fin>>number;
        s.hallNumber.setNumber(number);
        fin>>capacity;
        s.hallNumber.setCapacity(capacity);
        fin>>type;
        s.hallNumber.set3DCapable(type);
        screenings.push_back(s);
        count++;
    }
    fin.close();
}


ostream& operator<<(ostream& output, const Screening& s) { 
    output << setw(10) << left << s.id
           << setw(20) << left << s.movies.getTitle()
           << setw(20) << left << s.startTime
           << setw(20) << left << s.endTime
           << setw(20) << left << s.date
           << setw(20) << left << s.hallNumber.getNumber()
           << setw(20) << left << (s.is3d ? "3D" : "2D");
    return output;
}

Screening Screening::selectScreening(){
    DoubleLinkedList <Screening> screenings;
    Screening::readFile(screenings);
    Screening::viewScreenings(screenings);
    cout<<"\nEnter screening ID for Ticket: ";
    int screenId;
    cin>>screenId;
    for (int i=0; i<screenings.getSize();i++){
        if (screenId==screenings[i].id){
            return screenings[i];
        }
    }
    cout<<"No screening with Id \""<<screenId<<"\" found.";
    Screening empty;
    empty.setId(0);
    return empty;
}

void Screening:: allotHall(Hall &h){
    h.setNumber(this->hallNumber.getNumber());
    h.setCapacity(this->hallNumber.getCapacity());
    h.set3DCapable(this->hallNumber.get3DCapable());
    h.setSeats(h.getCapacity());
}

string Screening::getScreening() {
    string line = "";
    line += to_string(id) + "\n";
    line += startTime + "\n";
    line += endTime + "\n";
    line += date + "\n";
    line += hallNumber.getHall()+ "\n" + to_string(is3d)+"\n";
    line += movies.getMovie() + "\n";
    return line;
}