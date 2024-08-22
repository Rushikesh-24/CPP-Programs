#include <iostream>
using namespace std;
class MyClass {
private:
  int num;
public:
  MyClass(int n) : num(n) {}
  inline int getNum() { return num; }
  friend void displayNum(MyClass obj1, MyClass obj2);
};
void displayNum(MyClass obj1, MyClass obj2) {
  cout << "The numbers are: " << obj1.num << " and " << obj2.num << endl;
}
int main() {
  MyClass obj1(42);
  MyClass obj2(24);
  cout << "Inline function: " << obj1.getNum() << endl;
  displayNum(obj1, obj2);
  return 0;
}
