#include <iostream>
#include <string>
using namespace std;

// Template class for a comma-separated list
template <class T>
class CommaSeparatedList {
private:
    T* data;
    int size;

public:
    // Constructor to initialize data and size
    CommaSeparatedList(T* d, int s) : data(d), size(s) {}
    // Function to print the list
    void printList();
};

// Implementation of the printList function
template <class T>
void CommaSeparatedList<T>::printList() {
    cout << "Comma separated list:" << endl;
    for (int x = 0; x < size; ++x) {
        cout << data[x];
        if (x != size - 1)
            cout << ", ";
    }
    cout << endl << endl;
}

// Class to represent a Book
class Book {
    friend ostream& operator<<(ostream&, const Book&);

private:
    string title;
    int year;

public:
    void setBook(string, int);
};

// Function to set book details
void Book::setBook(string Title, int Year) {
    title = Title;
    year = Year;
}

// Overloading the << operator to output a Book object
ostream& operator<<(ostream& out, const Book& b) {
    out << b.title << " was published in " << b.year;
    return out;
}

// Class to represent a Customer
class Customer {
    friend ostream& operator<<(ostream&, const Customer&);

private:
    string name;
    double balDue;

public:
    void setCustomer(string, double);
};

// Function to set customer details
void Customer::setCustomer(string CustomerName, double BalanceDue) {
    name = CustomerName;
    balDue = BalanceDue;
}

// Overloading the << operator to output a Customer object
ostream& operator<<(ostream& out, const Customer& aCustomer) {
    out << aCustomer.name << " owes $" << aCustomer.balDue;
    return out;
}

int main() {
    int CommaSeparatedListSize;

    // Declare and assign values to four kinds of CommaSeparatedLists
    int someInts[] = { 12, 34, 55, 77, 99 };
    double someDoubles[] = { 11.11, 23.44, 44.55, 123.66 };
    Book someBooks[2];
    someBooks[0].setBook("Wizard of Oz", 1986);
    someBooks[1].setBook("Harry Potter", 2000);
    Customer someCustomers[6];
    someCustomers[0].setCustomer("Zaps", 23.55);
    someCustomers[1].setCustomer("Martin", 155.77);
    someCustomers[2].setCustomer("Fine", 333.88);
    someCustomers[3].setCustomer("Torrence", 123.99);
    someCustomers[4].setCustomer("Richard", 20.06);
    someCustomers[5].setCustomer("Curtin", 56999.19);

    // Calculate size and create CommaSeparatedList objects
    CommaSeparatedListSize = sizeof(someInts) / sizeof(someInts[0]);
    CommaSeparatedList<int> CommaSeparatedListOfIntegers(someInts, CommaSeparatedListSize);
    CommaSeparatedListSize = sizeof(someDoubles) / sizeof(someDoubles[0]);
    CommaSeparatedList<double> CommaSeparatedListOfDoubles(someDoubles, CommaSeparatedListSize);
    CommaSeparatedListSize = sizeof(someBooks) / sizeof(someBooks[0]);
    CommaSeparatedList<Book> CommaSeparatedListOfBooks(someBooks, CommaSeparatedListSize);
    CommaSeparatedListSize = sizeof(someCustomers) / sizeof(someCustomers[0]);
    CommaSeparatedList<Customer> CommaSeparatedListOfCustomers(someCustomers, CommaSeparatedListSize);

    // Use printList() with each CommaSeparatedList
    CommaSeparatedListOfIntegers.printList();
    CommaSeparatedListOfDoubles.printList();
    CommaSeparatedListOfBooks.printList();
    CommaSeparatedListOfCustomers.printList();

    return 0;
}
