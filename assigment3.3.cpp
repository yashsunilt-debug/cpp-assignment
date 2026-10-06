#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string n = "Unknown", int a = 0) {
        name = n;
        age = a;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNumber;
    string course;

public:
    Student(string n, int a, int roll, string c)
        : Person(n, a) {
        rollNumber = roll;
        course = c;
    }

    void displayStudent() const {
        display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
    }
};

class Employee : virtual public Person {
protected:
    int employeeId;
    float salary;

public:
    Employee(string n, int a, int id, float s)
        : Person(n, a) {
        employeeId = id;
        salary = s;
    }

    void displayEmployee() const {
        display();
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: " << salary << endl;
    }
};

class WorkingStudent : public Student, public Employee {
private:
    int workHours;

public:
    WorkingStudent(string n, int a, int roll, string c,
                   int id, float s, int hours)
        : Person(n, a), Student(n, a, roll, c), Employee(n, a, id, s) {
        workHours = hours;
    }

    void displayWorkingStudent() const {
        display();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Course: " << course << endl;
        cout << "Employee ID: " << employeeId << endl;
        cout << "Salary: " << salary << endl;
        cout << "Work Hours: " << workHours << endl;
    }
};

class Base1 {
public:
    void show() {
        cout << "Base1 Show" << endl;
    }

    void display() {
        cout << "Base1 Display" << endl;
    }
};

class Base2 {
public:
    void show() {
        cout << "Base2 Show" << endl;
    }

    void print() {
        cout << "Base2 Print" << endl;
    }
};

class Derived : public Base1, public Base2 {
public:
    void show() {
        cout << "Derived Show" << endl;
    }

    void resolveAmbiguity() {
        Base1::show();
        Base2::show();
        display();
        print();
    }
};

int main() {
    WorkingStudent ws("Bob Johnson", 25, 202, "CS", 5001, 45000, 20);

    ws.displayWorkingStudent();

    Derived d;
    d.show();
    d.resolveAmbiguity();

    return 0;
}
