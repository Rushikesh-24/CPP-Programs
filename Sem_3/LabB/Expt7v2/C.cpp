#include <iostream>
#include <iomanip> // Include the iomanip library for manipulators
using namespace std;

class MyClass {
    int data;

public:
    MyClass(int d) { data = d;}

    friend ostream& operator<<(ostream& os, const MyClass& obj) {
        os << obj.data;
        return os;
    }

    friend istream& operator>>(istream& is, MyClass& obj) {
        is >> obj.data;
        return is;
    }
};

int main() {
    MyClass obj1(10);
    cout << "Enter a number: ";
    cin >> obj1;

    cout << "The number you entered is: " << setw(10) << setfill('0') << obj1 << endl;
    return 0;
}