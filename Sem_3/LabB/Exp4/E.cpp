// #include <iostream>
// #include <vector>

// using namespace std;

// vector<int> multiplyWithScalar(const vector<int>& vec, int scalar) {
//     vector<int> result(vec.size());
//     for (size_t i = 0; i < vec.size(); ++i) {
//         result[i] = vec[i] * scalar;
//     }
//     return result;
// }

// vector<int> addVectors(const vector<int>& vec1, const vector<int>& vec2) {
//     if (vec1.size() != vec2.size()) {
//         throw invalid_argument("Vectors must be of the same size");
//     }
//     vector<int> result(vec1.size());
//     for (size_t i = 0; i < vec1.size(); ++i) {
//         result[i] = vec1[i] + vec2[i];
//     }
//     return result;
// }

// int main() {
//     int n;
//     cout << "Enter the size of the vector: ";
//     cin >> n;

//     vector<int> vec1(n);
//     cout << "Enter the elements of the vector: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> vec1[i];
//     }

//     int scalar;
//     cout << "Enter the scalar value to multiply: ";
//     cin >> scalar;

//     vector<int> multipliedVec = multiplyWithScalar(vec1, scalar);
//     cout << "Result of scalar multiplication: ";
//     for (int val : multipliedVec) {
//         cout << val << " ";
//     }
//     cout << endl;

//     vector<int> vec2(n);
//     cout << "Enter the elements of the second vector: ";
//     for (int i = 0; i < n; ++i) {
//         cin >> vec2[i];
//     }

//     try {
//         vector<int> addedVec = addVectors(vec1, vec2);
//         cout << "Result of vector addition: ";
//         for (int val : addedVec) {
//             cout << val << " ";
//         }
//         cout << endl;
//     } catch (const invalid_argument& e) {
//         cerr << e.what() << endl;
//     }

//     return 0;
// }
#include <iostream>
using namespace std;
class Vector {
  int *v;
  int size;

public:
  Vector(int size) {
    size = size;
    v = new int[size];
  }
  friend istream &operator>>(istream &is, Vector &obj) {
    for (int i = 0; i < obj.size; i++) {
      is >> obj.v[i];
    }
    return is;
  }
  int &operator[](int index) { return v[index]; }
  friend Vector multiply(Vector v, int scalar) {
    Vector x(v.size);
    for (int i = 0; i < v.size; i++) {
      x.v[i] = v.v[i] * scalar;
    }
    return x;
  }
  friend void displayVector( Vector& vec) {
    cout << "Vector elements: ";
    for (int i = 0; i < vec.size; ++i) {
      cout << vec[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  int n, scalar;
  cout << "Enter the size of the vector";
  cin >> n;
  Vector a(n);
  cout << "Enter the elements of the Vector";
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << "The elements to multiply with the Vector : ";
  cin >> scalar;
  Vector b = multiply(a, scalar);
  displayVector(b);
}