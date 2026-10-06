#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class PersonalDetails {
protected:
    string name;
    int age;
    string gender;

public:
    PersonalDetails(string n = "Unknown", int a = 0, string g = "Unknown") {
        name = n; age = a; gender = g;
    }

    void displayPersonal() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class SalaryDetails {
protected:
    float basicSalary;
    float allowances;
    float deductions;

public:
    SalaryDetails(float bs = 0, float al = 0, float de = 0) {
        basicSalary = bs; allowances = al; deductions = de;
    }

    float calculateNetSalary() const {
        return basicSalary + allowances - deductions;
    }

    void displaySalary() const {
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Allowances: " << allowances << endl;
        cout << "Deductions: " << deductions << endl;
        cout << "Net Salary: " << calculateNetSalary() << endl;
    }
};

class Employee : public PersonalDetails, public SalaryDetails {
private:
    int employeeId;
    string department;

public:
    Employee(string n, int a, string g, float bs, float al, float de,
             int id, string dept)
        : PersonalDetails(n, a, g), SalaryDetails(bs, al, de) {
        employeeId = id;
        department = dept;
    }

    void displayEmployee() const {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        displayPersonal();
        displaySalary();
    }
};

class Shape {
protected:
    string color;

public:
    Shape(string c = "Unknown") : color(c) {}

    virtual void draw() const = 0;
    virtual float area() const = 0;

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle(string c, float r) : Shape(c), radius(r) {}

    void draw() const override {
        cout << "Drawing a circle of radius " << radius
             << " with color " << color << endl;
    }

    float area() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle(string c, float l, float w) : Shape(c), length(l), width(w) {}

    void draw() const override {
        cout << "Drawing a rectangle of " << length << " x "
             << width << " with color " << color << endl;
    }

    float area() const override {
        return length * width;
    }
};

int main() {
    Employee emp("Alice Smith", 30, "Female", 60000, 15000, 5000,
                 1001, "IT");
    emp.displayEmployee();

    Circle circle("Red", 5);
    Rectangle rectangle("Blue", 10, 6);

    circle.draw();
    cout << "Circle Area: " << circle.area() << endl;

    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.area() << endl;

    return 0;
}
