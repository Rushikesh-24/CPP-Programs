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
    Employee()  {
      Id = 0;
      Current_Salary = 0;
      Updated_Salary = 0;
      status = "No Change";
    }

    string Name() { return name; }

    void input(int i) {
        Id = i;
        cout << "\nEnter the details for Employee ID " << Id << ":\n";
        cout << "Enter the name of the employee: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter the current salary of " << name << ": ";
        cin >> Current_Salary;
    }

    void new_salary() {
        cout << "\nUpdating salary details for " << name << " (ID: " << Id << ").\n";
        cout << "Current Salary: " << Current_Salary << endl;
        cout << "Enter the new salary: ";
        cin >> Updated_Salary;

        if (Updated_Salary >= 50000 && Updated_Salary > Current_Salary) {
            status = "Promoted";
        } else if (Updated_Salary > Current_Salary) {
            status = "Salary Increased";
        } else if (Updated_Salary == Current_Salary) {
            status = "No Change";
        } else {
            status = "Demoted";
        }
    }

    void display() {
        cout << Id << setw(20) << name << setw(20) << Current_Salary << setw(20)
             << Updated_Salary << setw(20) << status << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of employees: ";
    cin >> n;
    Employee CompanyA[n];

    cout << "\nEnter the Details\n";
    for (int i = 0; i < n; i++) {
        CompanyA[i].input(i + 1);
    }

    cout << "\nNew Salary Details\n";
    for (int i = 0; i < n; i++) {
        CompanyA[i].new_salary();
    }

    cout << "\nEmployee Salary Report\n";
    cout << "ID" << setw(20) << "Name" << setw(20) << "Current Salary" << setw(20)
         << "New Salary" << setw(20) << "Status" << endl;
    for (int i = 0; i < n; i++) {
        CompanyA[i].display();
    }

    return 0;
}
