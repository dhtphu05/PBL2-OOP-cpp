#include "../../Include/Staff.h"
void menuEditCustomer();
Staff::Staff()
{
}
Staff::Staff(string &ID, string &userName, string &DOB, string &fullName, string &email, string &phoneNumber, string &gender, string &password)
    : User(fullName, gender, email, DOB, phoneNumber)
{
    this->ID = ID;
    this->userName = userName;
    this->password = password;
}
void Staff::addCustomer()
{
    Customer customer;
    cout << "Tao khach hang moi" << endl;
    cin >> customer;
    customer.savetoFile();
}
void Staff::showCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    m.readfromFile(listCustomer);
    listCustomer.display();
}
void Staff::savetoFile()
{
}
void Staff::saveAgainFile(DoubleLinkedList<Customer> &listCustomer)
{
}

void Staff::readfromFile()
{
}

void Staff::editCustomer()
{
    DoubleLinkedList<Customer> listCustomer;
    Customer m;
    int count = false;
    m.readfromFile(listCustomer);
    string ID;
    cout << "Nhap ID: ";
    cin >> ID;
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].getID() == ID)
        {
            count = true;
            menuEditCustomer();
            cout << "Chon thong tin sua  " << endl;
            int choice;
            cin >> choice;
            string temp;
            switch (choice)
            {
            case 1:
                cout << "Nhap ten moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setFullName(temp);
                break;
            case 2:
                cout << "Nhap so dien thoai moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setPhoneNumber(temp);
                break;
            case 3:
                cout << "Nhap ngay sinh moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setDOB(temp);
            case 4:
                cout << "Nhap gioi tinh moi: " << endl;
                cin.ignore();
                getline(cin, temp);
                listCustomer[i].setGender(temp);
                break;
            default:
                cout << "Lua chon khong hop le" << endl;
                break;
            }
        }
    }
    if (count == false)
    {
        cout << "Khong tim thay khach hang" << endl;
    }
    m.saveAgainFile(listCustomer); //
}
void menuEditCustomer()
{
    cout << "1.Ten" << endl;
    cout << "2.So dien thoai" << endl;
    cout << "3.Ngay sinh" << endl;
    cout << "4.Gioi tinh" << endl;
}

void Staff::removeCustomer()
{
}
