#include <iostream>
#include <string>

using namespace std;

// Base class car
class car
{
protected:
    // Protected members to allow access in derived classes
    string name;
    int modelYear;

    // Protected assign function to allow derived classes to use it
    void assign(const car& c)
    {
        name = c.name;
        modelYear = c.modelYear;
    }

public:
    // Constructor to initialize car object
    car(const string& n, const int my) : name(n), modelYear(my) {}

    // Virtual print function to allow overriding
    virtual void print() const
    {
        cout << "Name: " << name << " model Year: " << modelYear << endl;
    }

    // Virtual assignment operator
    virtual car& operator=(const car& c)
    {
        if (this != &c)
        {
            assign(c);
        }
        return *this;
    }

    // Virtual destructor
    virtual ~car() = default;
};

// Derived class sedan
class sedan : public car
{
private:
    int mileage;

public:
    // Constructor to initialize sedan object
    sedan(const string& n, const int my, const int m) : car(n, my), mileage(m) {}

    // Overriding print function
    virtual void print() const override
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Mileage: " << mileage << endl;
    }

    // Overriding assignment operator
    virtual sedan& operator=(const sedan& s)
    {
        if (this != &s)
        {
            car::operator=(s); // Call base class assignment operator
            mileage = s.mileage;
        }
        return *this;
    }
};

// Derived class suv
class suv : public car
{
private:
    int miles;

public:
    // Constructor to initialize suv object
    suv(const string& n, const int my, const int m) : car(n, my), miles(m) {}

    // Overriding print function
    virtual void print() const override
    {
        cout << "Name: " << name << " model Year: " << modelYear << " Miles driven: " << miles << endl;
    }

    // Overriding assignment operator
    virtual suv& operator=(const car& c) override
    {
        if (const suv* s = dynamic_cast<const suv*>(&c))
        {
            car::operator=(c); // Call base class assignment operator
            miles = s->miles;
        }
        return *this;
    }

    // Overriding assignment operator for same type
    virtual suv& operator=(const suv& s)
    {
        if (this != &s)
        {
            car::operator=(s); // Call base class assignment operator
            miles = s.miles;
        }
        return *this;
    }

protected:
    // Protected assign function to allow derived classes to use it
    void assign(const suv& c)
    {
        car::assign(c);
        miles = c.miles;
    }
};

// Function to print car information
void printCarInfo(const car& c)
{
    c.print();
}

int main()
{
    car tesla("tesla", 2019);
    sedan hyundai("Hyundai", 2020, 23);
    suv ford("Ford", 2012, 20000);

    // Print information for tesla, hyundai, and ford
    printCarInfo(tesla);
    printCarInfo(hyundai);
    printCarInfo(ford);

    suv ford2("Ford", 2017, 10000);
    ford = ford2;

    // Print updated information for ford
    printCarInfo(ford);

    return 0;
}
