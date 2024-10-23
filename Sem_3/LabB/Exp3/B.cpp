#include <iostream>
using namespace std;
class MyClass {
private:
    int data;

public:
    MyClass() {
        data = 0;
    }

    MyClass(int value) {
        data = value;
    }

    MyClass(const MyClass& other) {
        data = other.data;
    }

    int getData() {
        return data;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2(10);
    MyClass obj3(obj2);
    cout << "Data of obj1: " << obj1.getData() << endl;
    cout << "Data of obj2: " << obj2.getData() << endl;
    cout << "Data of obj3: " << obj3.getData() << endl;
    return 0;
}
