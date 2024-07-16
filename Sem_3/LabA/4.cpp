#include <iostream>
using namespace std;
struct student {
  int roll_no;
  string name;
  int marks[6];
  float sgpa;
};
string gradeReverse(float sgpa);
float grade(int marks);
float sgpaCalculator(int marks[]);
int main() {
  int n;
  cout << "Enter the total number of students :";
  cin >> n;
  struct student classA[n];
  for (int i = 0; i < n; i++) {
    cout << "Enter Name of student : " << i + 1;
    cin >> classA[i].name;
    cout << "Enter the marks of student " << i + 1 << endl;
    classA[i].roll_no = i + 1;
    cout << "Maths :";
    cin >> classA[i].marks[0];
    cout << "LD :";
    cin >> classA[i].marks[1];
    cout << "DS :";
    cin >> classA[i].marks[2];
    cout << "OOPS :";
    cin >> classA[i].marks[3];
    cout << "TC :";
    cin >> classA[i].marks[4];
    cout << "CO :";
    cin >> classA[i].marks[5];
    classA[i].sgpa = sgpaCalculator(classA[i].marks);
  }
  for (int i = 0; i < n; i++) {
    cout << "Student " << i + 1 << endl
         << "Name : " << classA[i].name << endl
         << "SGPA is " << classA[i].sgpa << " and grade is "
         << gradeReverse(classA[i].sgpa) << endl;
  }
  return 0;
}
float grade(int marks) {
  if (marks > 107)
    return 10.0; // O
  if (marks > 99)
    return 9.5; // A+
  if (marks > 94)
    return 9.0; // A
  if (marks > 86)
    return 8.5; // B+
  if (marks > 82)
    return 8.0; // B
  if (marks > 69)
    return 7.0;
  if (marks > 63)
    return 6.0;
  if (marks > 57)
    return 5.0;
  if (marks > 50)
    return 4.0;
  return 0.0;
}

float sgpaCalculator(int marks[]) {
  return (grade(marks[0]) + grade(marks[1]) + grade(marks[2]) +
          grade(marks[3]) + grade(marks[4]) + grade(marks[5])) /
         6;
}

string gradeReverse(float sgpa) {
  if (sgpa >= 10)
    return "O";
  if (sgpa >= 9)
    return "A+"; // A+
  if (sgpa >= 8)
    return "A";
  if (sgpa >= 7)
    return "B+"; // B+
  if (sgpa >= 6)
    return "B";
  if (sgpa >= 5)
    return "C";
  if (sgpa >= 4)
    return "P";
  return "F";
}