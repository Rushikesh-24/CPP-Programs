#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
  int Id;
  string name;
  long int Current_Salary;
  long int Updated_Salary;
  string status;

public:
  Employee() { status = "No Change"; }

  string Name() { return name; }

  void input(int i) {
    Id = i;
    cout << "Enter the name of the employee : ";
    getline(cin, name);
    cin.ignore();
    cout << "Enter the current salary of the User :";
    cin >> Current_Salary;
    cin.ignore();
  }

  void new_salary(int i) {
    cout << "New salary :";
    cin >> Updated_Salary;
    if (Updated_Salary >= 50000 && Updated_Salary > Current_Salary) {
      status = "Promoted";
    } else if (Updated_Salary > Current_Salary) {
      status = "Salary Increased";
    } else if (Updated_Salary == Current_Salary) {
      status = "No change";
    } else {
      status = "Demoted";
    }
  }

  void dispay() {
    cout << Id << setw(20) << name << setw(20) << Current_Salary << setw(20)
         << Updated_Salary << setw(20) << status << endl;
  }
};

int main() {
  int n;
  cout << "Enter the number of Employee : ";
  cin >> n;
  cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  Employee CompanyA[n];
  cout << "Enter the Details" << endl;
  for (int i = 0; i < n; i++) {
    CompanyA[i].input(i + 1);
  }
  cout << "New Salary Details" << endl;
  for (int i = 0; i < n; i++) {
    cout << "New Salary" << endl;
    cout << "Name : " << CompanyA[i].Name() << " "
         << "Id : " << i + 1 << endl;
    CompanyA[i].new_salary(i);
  }
  cout << "ID" << setw(20) << "Name" << setw(20) << "Current Salary" << setw(20)
       << "New Salary" << setw(20) << "Status" << endl;
  for (int i = 0; i < n; i++) {
    CompanyA[i].dispay();
  }
  return 0;
}