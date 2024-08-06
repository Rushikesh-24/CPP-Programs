#include <iostream>
using namespace std;
class MyClass {
private:
    int num;

public:
    MyClass(int n) : num(n) {}
    inline int getNum() {
        return num;
    }
    friend void displayNum(MyClass obj);
};
void displayNum(MyClass obj) {
    cout << "The number is: " << obj.num << endl;
}

int main() {
    MyClass obj(42);
    int num = obj.getNum();
    cout << "Inline function: " << num << endl;
    displayNum(obj);
    return 0;
}