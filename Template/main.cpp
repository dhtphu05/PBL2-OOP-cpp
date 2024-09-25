
#include "DoubleLinkedList.h"

class User {
private:
    int id;
    string name;
    string email;

public:
    // Parameterized constructor
    User(int id, string name, string email) : id(id), name(name), email(email) {}

    // Getters
    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }


    string getEmail() const {
        return email;
    }

    // Setters (for updating user info)
    void setName(const string& newName) {
        name = newName;
    }

    void setEmail(const string& newEmail) {
        email = newEmail;
    }

    // Display user info
    void Display()  {
        cout << "User ID: " << id << ", Name: " << name << ", Email: " << email << endl;
    }
};
int main(){
    DoubleLinkedList<User> users;
    User user1(1, "Alice", "heehe");
    users.push_back(user1);
    User user2(2, "Bob", "haha");
    users.push_back(user2);
    User user3(3, "Charlie", "hoho");
    users.push_front(user3);
    User user4(4, "David", "hihi");
    users.insert(1,user4);
    users.display();
    users[1].Display();
    cout<<users.getSize()<<endl;

}