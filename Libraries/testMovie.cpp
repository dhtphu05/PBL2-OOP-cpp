#include "Movie.cpp"
#include <windows.h>
int main(){
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Movie movie;
    movie.addMovie();
    movie.showMovie();
    return 0;
}