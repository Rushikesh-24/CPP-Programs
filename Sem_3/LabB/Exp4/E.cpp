#include<iostream>
using namespace std;

class Vector {
  int* a;
  int size;
public:
  Vector(int s = 3) {
    size = s;
    a = new int[size];
    for (int i = 0; i < size; i++) {
      a[i] = 0;
    }
  }
  void getdata() {
    cout << "Enter the elements of the Vector" << endl;
    for (int i = 0; i < size; i++) {
      cin >> a[i];
    }
  }

  Vector operator*(int p) {
    Vector v3(size);
    for (int i = 0; i < size; i++) {
      v3.a[i] = a[i] * p;
    }
    return v3;
  }
  Vector operator+(const Vector& v) {
    if (size != v.size) {
      cout << "Error: Vector sizes are not the same." << endl;
      return Vector();
    }
    Vector result(size);
    for (int i = 0; i < size; i++) {
      result.a[i] = a[i] + v.a[i];
    }
    return result;
  }

  void display() {
    for (int i = 0; i < size; i++) {
      cout << " " << a[i];
    }
    cout<<endl;
  }
};

int main() {
  int n, scalar;
  cout << "Enter the size of the vector: ";
  cin >> n;
  Vector v1(n), v2(n) ,v3(n);
  v1.getdata();
  cout << "Enter scalar: ";
  cin >> scalar;
  v2 = v1 * scalar;
  v3 = v1 + v2;
  v2.display();
  v3.display();
}