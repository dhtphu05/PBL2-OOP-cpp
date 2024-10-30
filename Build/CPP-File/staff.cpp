#include "../../Include/Staff.h"
void menuEditCustomer();
Staff::Staff()
{
    this->ID = count;
    count++;
}
Staff::Staff(string &userName, string &password, string &fullName, string &phoneNumber, string &DOB, string &gender)
    : User(username, password, fullName, phoneNumber, DOB, gender)
{
}
// void Staff::addCustomer()
// {
//     Customer customer;
//     cout << "Tao khach hang moi" << endl;
//     cin >> customer;
//     customer.savetoFile();
// }
void Staff::addCustomer()
{
    Customer customer;
    DoubleLinkedList<Customer> listCustomer;
    customer.readfromFile(listCustomer);

    cout << "Tao khach hang moi" << endl;
    cin >> customer;
    int newID = Customer::count + 1; // Khởi tạo ID mới bằng ID cao nhất + 1

    // Kiểm tra xem ID đã tồn tại chưa
    while (isIDExists(listCustomer, newID))
    {
        newID++; // Tăng ID cho đến khi tìm thấy ID không trùng
    }
    customer.setID(newID); // Gán ID duy nhất cho khách hàng mới

    // Lưu thông tin khách hàng vào file
    customer.savetoFile();
}

// Hàm kiểm tra ID đã tồn tại
bool Staff::isIDExists(DoubleLinkedList<Customer> &listCustomer, int id)
{
    for (int i = 0; i < listCustomer.getSize(); i++)
    {
        if (listCustomer[i].returnID() == id) //
        {
            return true; // ID đã tồn tại
        }
    }
    return false; // ID không tồn tại
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
