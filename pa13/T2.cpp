#include <iostream>
#include <string>
using namespace std;

// Template function to find the largest of three objects
template <class T>
void findBiggest(T a, T b, T c) {//Template function parameter type error
    T large = a;
    if (b > large)
        large = b;
    if (c > large) // Fix comparison to find the largest
        large = c;
    cout << "The largest of " << a << ", " << b << ", and " << c << " is " << large << endl;
}

// Template function to find the larger of two objects
template <class T>
void findBiggest(T a, T b) {
    T large = a;
    if (b > large) // Fix comparison to find the larger
        large = b;
    cout << "The larger of " << a << " and " << b << " is " << large << endl;
}

// Class to represent a Bank Account
class BankAccount {
    friend ostream& operator<<(ostream&, const BankAccount&);

private:
    string name;
    int amount;

public:
    BankAccount(const string&, const int);
    bool operator>(const BankAccount&) const;
};

// Constructor to initialize BankAccount with a name and amount
BankAccount::BankAccount(const string& name, const int amount) : name(name), amount(amount) {}

// Overloading the << operator to output a BankAccount object
ostream& operator<<(ostream& out, const BankAccount& ba) {
    out << "Name: " << ba.name << " Amount: " << ba.amount << endl;
    return out;
}

// Overloading the > operator to compare two BankAccount objects
bool BankAccount::operator>(const BankAccount& ba) const {
    return amount > ba.amount; // Simplify comparison
}

int main() {
    // Creating BankAccount objects with name and amount
    BankAccount bAA("A", 800);
    BankAccount bAB("B", 120);
    BankAccount bAC("C", 500);

    // Finding and printing the largest BankAccount among pairs and triplets
    findBiggest(bAA, bAB);
    findBiggest(bAB, bAC);
    findBiggest(bAC, bAA);
    findBiggest(bAA, bAB, bAC);

    return 0;
}
