#include <iostream>
#include <string>
using namespace std;

// Define the User class
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
    void display() const {
        cout << "User ID: " << id << ", Name: " << name << ", Email: " << email << endl;
    }
};

// Define the LinkedList template
template <typename T>
class Node {
public:
    T data;
    Node* next;
    // Constructor that uses initialization list to initialize data
    Node(const T& data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Add element at the end of the list
    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
        size++;
    }

    // Get element by index (like array access)
    T& operator[](int index) {
        if (index >= size || index < 0) {
            throw out_of_range("Index out of range");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    // Get the size of the list
    int getSize() const {
        return size;
    }

    // Display all elements in the list
    void display() const {
        Node<T>* current = head;
        while (current != nullptr) {
            current->data.display();
            current = current->next;
        }
        cout << endl;
    }

    // Update a user by ID
    void updateUserById(int id, const string& newName, const string& newEmail) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data.getId() == id) {
                current->data.setName(newName);
                current->data.setEmail(newEmail);
                return;
            }
            current = current->next;
        }
        cout << "User with ID " << id << " not found!" << endl;
    }
};

// Main function to demonstrate usage
int main() {
    // Create a LinkedList of User objects
    LinkedList<User> userList;

    // Add some users to the list
    userList.push_back(User(4,"Doan Hoang Thien Phu", "dhtphu05"));
    userList.push_back(User(1, "Alice", "alice@example.com"));
    userList.push_back(User(2, "Bob", "bob@example.com"));
    userList.push_back(User(3, "Charlie", "charlie@example.com"));

    // Display all users
    cout << "All users in the list:" << endl;
    userList.display();

    // Update a user by ID
    cout << "Updating user with ID 2..." << endl;
    userList.updateUserById(2, "Bob Marley", "bob.marley@example.com");
    userList[0].display();
    // Display all users after update
    cout << "All users after update:" << endl;
    userList.display();
    cout<<"lllllllllllllllll"<<userList.getSize();
    return 0;
}
