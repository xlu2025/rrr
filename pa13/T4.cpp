#include <iostream>
#include <string>
using namespace std;

// Template class to perform various operations on two variables of type T
template <class T>
class Calculator
{
private:
    T num1;
    T num2;

public:
    // Constructor to initialize the two numbers
    Calculator(T n1, T n2);

    // Functions to perform arithmetic operations
    T add();
    T subtract();
    T multiply();
    T divide();

    // Function to determine which value is greater
    bool isgreater();
};

// Constructor implementation
template <class T>
Calculator<T>::Calculator(T n1, T n2) : num1(n1), num2(n2) {}

// Function to add two numbers
template <class T>
T Calculator<T>::add()
{
    return num1 + num2;
}

// Function to subtract two numbers
template <class T>
T Calculator<T>::subtract()
{
    return num1 - num2;
}

// Function to multiply two numbers
template <class T>
T Calculator<T>::multiply()
{
    return num1 * num2;
}

// Function to divide two numbers
template <class T>
T Calculator<T>::divide()
{
    // Check for division by zero
    if (num2 == 0)
    {
        throw invalid_argument("Division by zero");
    }
    return num1 / num2;
}

// Function to check if num1 is greater than num2
template <class T>
bool Calculator<T>::isgreater()
{
    return num1 > num2;
}

int main()
{
    // Integer operations
    Calculator<int> calc(10, 4);
    cout << "Integer operations:" << endl;
    cout << "Add: " << calc.add() << endl;
    cout << "Subtract: " << calc.subtract() << endl;
    cout << "Multiply: " << calc.multiply() << endl;
    cout << "Divide: " << calc.divide() << endl;
    cout << "Is greater: " << std::boolalpha << calc.isgreater() << endl;

    // Double operations
    Calculator<double> calc2(10.234, 4.235);
    cout << "\nDouble operations:" << endl;
    cout << "Add: " << calc2.add() << endl;
    cout << "Subtract: " << calc2.subtract() << endl;
    cout << "Multiply: " << calc2.multiply() << endl;
    cout << "Divide: " << calc2.divide() << endl;
    cout << "Is greater: " << std::boolalpha << calc2.isgreater() << endl;

    // String operations
    Calculator<string> calc3("Hello", "World");
    cout << "\nString operations:" << endl;
    cout << "Add: " << calc3.add() << endl;
    cout << "Is greater: " << std::boolalpha << calc3.isgreater() << endl;

    return 0;
}
