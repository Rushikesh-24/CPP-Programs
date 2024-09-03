#include <iostream>
using namespace std;
class Counter {
private:
    int count;

public:
    Counter(){
        count = 10;
    }
    void operator++() {
        ++count;
    }
    void operator++(int) {
        ++count;
    }
    void operator--() {
        --count;
    }
    void operator--(int) {
        --count;
    }
    void display() {
        cout << count << endl;
    }
};

int main() {
    Counter c1;
    cout<<"Initial Count: ";
    c1.display();
    ++c1;
    cout<<"After Pre-Increment: ";
    c1.display();
    c1++; 
    cout<<"After Post-Increment: ";
    c1.display();
    --c1; 
    cout<<"After Pre-Decrement: ";
    c1.display();
    c1--; 
    cout<<"After Post-Decrement: ";
    c1.display();
    return 0;
}