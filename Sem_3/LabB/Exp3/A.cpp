#include <iostream>
using namespace std;

class MyClass {
  int num;

public:
  MyClass(int n) { num = n; }

  void display() { cout << "The number is: " << num << endl; }
};

int main() {
  MyClass obj(10);
  obj.display();
  return 0;
}