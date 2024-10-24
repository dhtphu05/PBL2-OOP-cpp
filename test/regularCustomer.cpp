#include "regularCustomer.h"

int RegularCustomer::count = 0;

//default constructor

RegularCustomer::RegularCustomer(const int id, const string& name, int age, const string& contactInfo)
    : Customer(name, age, contactInfo), id(id) {}


void RegularCustomer::setCount(int count) {
    RegularCustomer::count = count;
}

int RegularCustomer::getCount() const {
    return count;
}

void RegularCustomer::addCustomer(){

    cout << "Nhap ten cua khach hang: ";
    getline(cin, name);
    
    cout << "Nhap tuoi cua khach hang: ";
    cin >> age;
    cin.ignore();
    
    cout << "So dien thoai: ";
    getline(cin, contactInfo);
    count++;
    if (!saveToFile()){
        cout<<"Failed to save customer to file"<<endl;
    }
}

void RegularCustomer::viewCustomer(Customer* customers, int size) {
    if (size == 0) {
        cout << "Khong co khach hang nao da dang ky." << endl;
        return;
    }

    cout << "Danh sach khach hang:" << endl;
    cout << "----------------" << endl;

    for (int i = 0; i < size; i++) {
        cout << static_cast<RegularCustomer*>(customers)[i] << endl; 
        cout<<"----------------" << endl;
    }
    cout << "So luong khach hang da dang ky la: " << count << endl;
}


bool RegularCustomer::saveToFile() {
    ofstream fout;
    try{
    fout.open("regularCustomers.txt",ios::app);
    if (fout.fail()){
        throw runtime_error("Error opening regularCustomers.txt for writing");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return false;
    }
    fout<<id<<endl;
    fout<<name<<endl;
    fout<<age<<endl;
    fout<<contactInfo<<endl;
    fout.close();
    cout << "Dang ky thong tin khach hang thanh cong." << endl;
    return true;
}

void RegularCustomer::readFile(Customer *c, int &index) {
    ifstream fin;
    try{
    fin.open("regularCustomers.txt");
    if (fin.fail()){
        throw runtime_error("Error opening regularCustomers.txt for reading");
    }
    }
    catch(runtime_error &e){
        cout<<e.what()<<endl;
        return;
    }
    while (fin>>static_cast<RegularCustomer*>(c)[index].id ) {
        fin.get();
        getline(fin,static_cast<RegularCustomer*>(c)[index].name);
        fin>>static_cast<RegularCustomer*>(c)[index].age;
        fin.get();
        getline(fin,static_cast<RegularCustomer*>(c)[index].contactInfo);
        index++;
        count++;
    }
    fin.close();
    cout << "Regular customers read from file successfully." << endl;
}

ostream& operator<<(ostream& output, const RegularCustomer& customer) {
    output<<"ID: "<<customer.id<<endl;
    output <<"Ten: " << customer.name << endl;
    output <<"Tuoi: " << customer.age << endl;
    output <<"Thong tin lien lac: " << customer.contactInfo << endl;
    return output;
}
