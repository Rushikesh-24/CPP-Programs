#include <iostream>
using namespace std;

class Base {
public:
    int baseData;
};

class Intermediate1 : virtual public Base {
public:
    int intermediate1Data;
};

class Intermediate2 : virtual public Base {
public:
    int intermediate2Data;
};

class Derived : public Intermediate1, public Intermediate2 {
public:
    int derivedData;
};

int main() {
    Derived obj;
    obj.baseData = 10;
    obj.intermediate1Data = 20;
    obj.intermediate2Data = 30;
    obj.derivedData = 40;
    cout << "Base Data: " << obj.baseData << endl;
    cout << "Intermediate1 Data: " << obj.intermediate1Data << endl;
    cout << "Intermediate2 Data: " << obj.intermediate2Data << endl;
    cout << "Derived Data: " << obj.derivedData << endl;
    return 0;
}
