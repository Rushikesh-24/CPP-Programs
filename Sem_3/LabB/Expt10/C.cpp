#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student {
public:
  string name;
  string rollNo;
  string address;
  string branch;

  void getData() {
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll No: ";
    getline(cin, rollNo);
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter Branch: ";
    getline(cin, branch);
  }

  void saveToFile() const {
    ofstream file(name + ".txt", ios::trunc);
    file << name << endl << rollNo << endl << address << endl << branch;
    file.close();
    cout << "Student data saved successfully!" << endl;
  }

  void displayData() const {
    cout << "+----------------+----------------------+" << endl;
    cout << "| Field          | Value                |" << endl;
    cout << "+----------------+----------------------+" << endl;
    cout << "| Name           | " << setw(20) << left << name << "|" << endl;
    cout << "| Roll No        | " << setw(20) << left << rollNo << "|" << endl;
    cout << "| Address        | " << setw(20) << left << address << "|" << endl;
    cout << "| Branch         | " << setw(20) << left << branch << "|" << endl;
    cout << "+----------------+----------------------+" << endl;
    return;
  }

  bool loadFromFile(const string &fileName) {
    ifstream file(fileName + ".txt");
    if (file.is_open()) {
      getline(file, name);
      getline(file, rollNo);
      getline(file, address);
      getline(file, branch);
      file.close();
      return true;
    }
    return false;
  }
};

void addStudent() {
  Student student;
  student.getData();
  student.saveToFile();
}

void searchAndUpdateStudent() {
  string name;
  cout << "Enter student name to search: ";
  getline(cin, name);

  Student student;
  if (student.loadFromFile(name)) {
    cout << "Student found!" << endl;

    string enteredRollNo;
    cout << "Enter the Roll No to confirm: ";
    getline(cin, enteredRollNo);

    if (enteredRollNo == student.rollNo) {
      student.displayData();
      cout << "Roll No matches. Do you want to update the details? (y/n): ";
      char choice;
      cin >> choice;
      cin.ignore();
      if (choice == 'y' || choice == 'Y') {
        student.getData();
        student.saveToFile();
        cout << "Details updated successfully!" << endl;
      }
    } else {
      cout << "Error: The entered Roll No does not match the one in the file."
           << endl;
      cout << "Update cancelled for security reasons." << endl;
    }
  } else {
    cout << "Student with name '" << name << "' not found!" << endl;
  }
}

int main() {
  int choice;
  do {
    cout << "\n1. Add Student" << endl;
    cout << "2. Search and Update Student" << endl;
    cout << "3. Display Student" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character left in the input buffer

    switch (choice) {
    case 1:
      addStudent();
      break;
    case 2:
      searchAndUpdateStudent();
      break;

    case 3: {
      Student student;
      string name;
      cout << "Enter student name to display: ";
      getline(cin, name);
      if (student.loadFromFile(name)) {
        student.displayData();
      } else {
        cout << "Student with name '" << name << "' not found!" << endl;
      }
      break;
    }
    case 4:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice! Please try again." << endl;
      break;
    }
  } while (choice != 4);

  return 0;
}