#include <iostream>
#include <string>
using namespace std;
int main(){
    cout<<"He thong dat ve xem phim"<<endl;
    cout<<"1. Dat ve"<<endl;
    cout<<"2. Thoat dat ve"<<endl;
    int choiceMenuMain;
    cout<<"Nhap lua chon cua ban: ";
    cin>>choiceMenuMain;
    switch (choiceMenuMain)
    {
    case 1:
        system("cls");
        cout<<"Chon ngay chieu: "<<endl;
        cout<<"1. 17/10/2024"<<endl;
        cout<<"2. 18/10/2021"<<endl;
        cout<<"3. 19/10/2021"<<endl;
        cout<<"4. 20/10/2021"<<endl<<endl;
        int choiceDate;
        cout<<"Nhap lua chon cua ban: ";
        cin>>choiceDate;
        switch (choiceDate)
        {
            case 1:
            
        }

        break;
    
    default:
        return 0;
        break;
    }
}