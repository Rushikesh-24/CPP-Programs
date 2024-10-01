#include <iostream>
using namespace std;
class String {
  char str[20];

public:
  String() { str[0] = '\0'; }

  ~String() {
    
  }
String(const char *s) {
    strncpy(str, s, sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';
}

  String &operator=(const String &x) {
    if (this != &x) {
      strncpy(str, x.str, sizeof(str) - 1);
      str[sizeof(str) - 1] = '\0';
    }
    return *this;
  }
  friend String operator+(const String &s1, const String &s2) {
    String temp;
    strncpy(temp.str, s1.str, sizeof(temp.str) - 1);
    temp.str[sizeof(temp.str) - 1] = '\0';
    strncat(temp.str, s2.str, sizeof(temp.str) - strlen(temp.str) - 1);
    return temp;
  }

  String &operator=(const char *s) {
    strncpy(str, s, sizeof(str) - 1);
    str[sizeof(str) - 1] = '\0';
    return *this;
  }
  friend void operator<<(ostream &os, const String &s) { os << s.str; }
};
int main() {
  String s1, s2("World!"), s3;
  s1 = "Hello, ";
  s3 = s1 + s2;
  cout << s3;
}