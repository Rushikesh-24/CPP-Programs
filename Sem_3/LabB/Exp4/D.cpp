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
  friend istream &operator>>(istream &is, String obj) {
    is >> obj.s;
    return is;
  }
  friend ostream &operator<<(ostream &os, const String obj) {
    os << obj.s;
    return os;
  }
  friend String operator+(String b, String a) {
    String temp;
    strcat(temp.s, b.s);
    strcat(temp.s, a.s);
    return temp;
  }
  int length() { 
    return strlen(s); 
  }
};
int main() {
  String s1, s2, s3;
  cout << "Enter string A : ";
  cin >> s1;
  cout << "Enter string B : ";
  cin >> s2;
  s3 = s1 + s2;
  cout << endl << "Output String1 + String2: ";
  cout << s3;
  if (s1.length() < s2.length()) {
    cout << endl << "String A is smaller than String B"<<endl;
  } else {
    cout << endl << "String B is smaller than String A"<<endl;
  }
  return 0;
}