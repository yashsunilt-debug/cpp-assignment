#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person(string n = "Unknown", int a = 0, string addr = "Unknown")
        : name(n), age(a), address(addr) {
    }

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public Person {
private:
    int rollNumber;
    float marks;

public:
    Student(string n, int a, string addr, int roll, float m)
        : Person(n, a, addr), rollNumber(roll), marks(m) {
    }

    void displayStudent() const {
        displayPerson();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle(string b = "Unknown", string m = "Unknown", int y = 0)
        : brand(b), model(m), year(y) {
    }

    void displayVehicle() const {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
protected:
    int numberOfDoors;
    string fuelType;

public:
    Car(string b, string m, int y, int doors, string fuel)
        : Vehicle(b, m, y), numberOfDoors(doors), fuelType(fuel) {
    }

    void displayCar() const {
        displayVehicle();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity;
    int range;

public:
    ElectricCar(string b, string m, int y, int doors, string fuel,
                int battery, int r)
        : Car(b, m, y, doors, fuel),
          batteryCapacity(battery), range(r) {
    }

    void displayElectricCar() const {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh"
             << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main() {
    Student s("John Doe", 20, "123 Main St", 101, 85.5);
    s.displayStudent();

    ElectricCar e("Tesla", "Model 3", 2023, 4, "Electric", 100, 650);
    e.displayElectricCar();

    return 0;
}
