#include <iostream>
using namespace std;
class Student {
private:
  string name;
  int age;

public:
  Student() {
    name = "Unnamed";
    age = 0;
  }
  Student(string Name, int Age) {
    name = Name;
    age = Age;
  }
  void setDetails(string Name, int Age) {
    name = Name;
    age = Age;
  }
  void display() { cout << "Name: " << name << ", Age: " << age << endl; }
};

int main() {
  int numberOfStudents;
  cout << "Enter the number of students: ";
  cin >> numberOfStudents;
  Student *students = new Student[numberOfStudents];
  for (int i = 0; i < numberOfStudents; ++i) {
    string name;
    int age;
    cout << "Enter details for student " << i + 1 << " (name age): ";
    cin >> name >> age;
    students[i].setDetails(name, age);
  }
  cout << "\nDisplaying student details:\n";
  for (int i = 0; i < numberOfStudents; ++i) {
    students[i].display();
  }
  delete[] students;
  return 0;
}
