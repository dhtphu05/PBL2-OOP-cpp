#include "../../Include/User.h"

void Management::addMovie(DoubleLinkedList<Movie> &movies)
{

    Movie newMovie;
    cout << "Them moi 1 bo phim: " << endl;
    cout << "ID phim: ";
    cin >> newMovie.ID_Movie;
    cout << "Ten phim: ";
    cin.ignore();                 // hàm này để xóa bộ nhớ đệm của cin
    getline(cin, newMovie.title); // hàm này để nhập chuỗi có khoảng trắng
    cout << "The Loai: ";
    // getline(cin, newMovie.genre);
    // cout << "Ngay ra mat: ";
    // getline(cin, newMovie.releaseDate);
    // cout << "Dao dien: ";
    // getline(cin, newMovie.director);
    // cout << "Rating: ";
    // getline(cin, newMovie.rating);
    // cout << "Thoi luong: ";
    // getline(cin, newMovie.duration);
    // cout << "Dien Vien: ";
    // getline(cin, newMovie.actor);
    // cout << "Ngon Ngu: ";
    // getline(cin, newMovie.language);
    // cout << "Mo ta: ";
    // getline(cin, newMovie.description);
    movies.push_back(newMovie);
}
void Management ::showMovie(DoubleLinkedList<Movie> &movies)
{
    movies.display();
}
// void Management::editMovie(DoubleLinkedList<Movie> &movies)
// {
//     string ID;
//     Movie movie;
//     cout << "Nhập ID phim cần sửa: ";
//     cin >> ID;
//     while (movies != NULL)
//     {
//         movie = movies.
//     }
// }
