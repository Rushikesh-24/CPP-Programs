#include<iostream>
using namespace std;
class Base {
public:
    int value;

    Base(int val) {
        value = val;
        cout << "Base class constructor called with value: " << value << endl;
    }
};

class Derived : public Base {
public:
    Derived(int val) : Base(val) {
        cout << "Derived class constructor called" << endl;
    }
};

int main() {
    Derived d(10);
    return 0;
}