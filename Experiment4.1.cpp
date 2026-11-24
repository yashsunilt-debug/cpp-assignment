#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
public:
    int add(int a, int b) { return a + b; }
    double add(double a, double b) { return a + b; }
    int add(int a, int b, int c) { return a + b + c; }

    double divide(int a, int b) {
        if (b == 0) {
            cout << "Division by zero!" << endl;
            return 0;
        }
        return (double) a / b;
    }

    double divide(double a, double b) {
        if (b == 0) {
            cout << "Division by zero!" << endl;
            return 0;
        }
        return a / b;
    }
};

class Distance {
private:
    int feet;
    int inches;

    void normalize() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

public:
    Distance(int f = 0, int i = 0) : feet(f), inches(i) {
        normalize();
    }

    Distance operator+(const Distance& d) {
        Distance result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;
        result.normalize();
        return result;
    }

    Distance operator-(const Distance& d) {
        int totalInches1 = feet * 12 + inches;
        int totalInches2 = d.feet * 12 + d.inches;
        int diff = totalInches1 - totalInches2;

        if (diff < 0) {
            cout << "Negative distance!" << endl;
            return Distance(0, 0);
        }

        return Distance(diff / 12, diff % 12);
    }

    bool operator==(const Distance& d) {
        return (feet == d.feet && inches == d.inches);
    }

    friend ostream& operator<<(ostream& out, const Distance& d) {
        out << d.feet << " feet " << d.inches << " inches";
        return out;
    }
};

int main() {
    Calculator calc;

    cout << "Add int: " << calc.add(5, 3) << endl;
    cout << "Add double: " << calc.add(5.5, 3.2) << endl;
    cout << "Add 3 ints: " << calc.add(5, 3, 2) << endl;

    Distance d1(5, 8), d2(3, 6);
    Distance d3 = d1 + d2;
    Distance d4 = d1 - d2;

    cout << "d1: " << d1 << endl;
    cout << "d2: " << d2 << endl;
    cout << "d1 + d2: " << d3 << endl;
    cout << "d1 - d2: " << d4 << endl;
    cout << "d1 == d2: " << (d1 == d2 ? "True" : "False") << endl;

    return 0;
}
