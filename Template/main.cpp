
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
    users.push_back(User(1, "Alice", "eheh"));
    users.push_back(User(2, "Bob", "eheh"));
    users.push_back(User(3, "Charlie", "eheh"));
    users.push_back(User(4, "David", "eheh"));
    users.push_back(User(5, "Eve", "eheh"));
    users.push_back(User(6, "Frank", "eheh"));
    users.push_back(User(7, "Grace", "eheh"));
}