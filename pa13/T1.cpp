#include <iostream>
#include <string>
using namespace std;

// Template function to add two objects of the same type
template <class T>
T add(T x, T y)//Template function definition error
{
	T sum = x + y; // Initialize sum with the correct type and value
	return sum; // Return the sum of x and y
}

// Class to represent a Person
class Person
{
	friend ostream& operator<<(ostream&, const Person&);

private:
	string lastName;
	string firstName;
	int age;

public:
	void setValues(string, string, int); // Method to set values
	Person operator+(const Person&) const; // Operator+ to add ages of two Person objects
};

// Overloading the << operator to output a Person object
ostream& operator<<(ostream& out, const Person& per)//No operator overload returning an output stream
{
	out << per.firstName << " " << per.lastName << " " << per.age << " years old" << endl;
	return out; // Add return statement
}

// Setting values for a Person object
void Person::setValues(string last, string first, int age)
{
	lastName = last;
	firstName = first;
	this->age = age; // Correctly assign the age
}

// Overloading the + operator to add ages of two Person objects
Person Person::operator+(const Person& p) const
{
	Person temp;
	temp.lastName = "of Age";
	temp.firstName = "Sum";
	temp.age = this->age + p.age; // Correctly sum the ages
	return temp;
}

int main()
{
	// Test cases for the add function template
	int a = 7, b = 26, c;
	double d = 39.25, e = 2.01, f;

	// Creating and setting values for Person objects
	Person g, h, i;
	g.setValues("Mitchell", "Donald", 40);
	h.setValues("Clayton", "Rita", 35);

	// Adding integers, doubles, and Person objects
	c = add(a, b);
	f = add(d, e);
	i = add(g, h);

	// Output the results
	cout << c << endl;
	cout << f << endl;
	cout << i << endl;

	return 0;
}
