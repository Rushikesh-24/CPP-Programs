#include <iostream>
#include <iomanip>
using namespace std;

class Counter {
private:
    int count;
    string lastOperation;

public:
    Counter() : count(10), lastOperation("Initial Count") {}

    void operator++() {
        ++count;
        lastOperation = "++Object (Pre-Increment)";
    }

    void operator++(int) {
        ++count;
        lastOperation = "Object++ (Post-Increment)";
    }

    void operator--() {
        --count;
        lastOperation = "--Object (Pre-Decrement)";
    }

    void operator--(int) {
        --count;
        lastOperation = "Object-- (Post-Decrement)";
    }

    void display() {
        cout << left << setw(25) << lastOperation <<right<<setw(5)<< count << endl;
    }
};

int main() {
    Counter c1;
    cout << left << setw(25) << "Operation" <<right<< "Count" << endl;
    cout << "---------------------------------" << endl;
    c1.display();
    ++c1;
    c1.display();
    c1++;
    c1.display();
    --c1;
    c1.display();
    c1--;
    c1.display();
    return 0;
}