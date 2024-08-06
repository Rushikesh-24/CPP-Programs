#include <cstring>
#include <iostream>
#include <string>
using namespace std;
class String {
  char *s;
public:
  String() {
    s = new char[100];
  }
  friend istream &operator>>(istream &is, String &obj) {
    is >> obj.s;
    return is;
  }
  friend ostream &operator<<(ostream &os, const String &obj) {
    os << obj.s;
    return os;
  }
  friend String operator+(String &b, String &a) {
    String temp;
    temp.s = strcat(b.s, a.s);
    return temp;
  }
  int length() { return strlen(s); }
};
int main() {
  String a, b, c;
  cout << "Enter string A : ";
  cin >> a;
  cout << "Enter string B : ";
  cin >> b;
  c = a + b;
  cout << endl << "Output : ";
  cout << c;
  if (a.length() < b.length()) {
    cout << endl << "String A is smaller than String B";
  } else {
    cout << endl << "String B is smaller than String A";
  }
  return 0;
}