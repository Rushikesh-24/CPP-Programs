#include <iostream>
using namespace std;
class Counter {
private:
    int count;

public:
    Counter(){
        count = 0;
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
        cout << "Count: " << count << endl;
    }
};

int main() {
    Counter c1;
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