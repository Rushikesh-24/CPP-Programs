#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Person {
public:
  string name;
  long int phone;

  Person() : name(""), phone(0) {}

  Person(string name, long int phone) {
    this->name = name;
    this->phone = phone;
  }
};

void saveToFile(const vector<Person> &persons) {
  ofstream file("directory.txt", ios::app);
  if (file.tellp() == 0) {
    file << left << setw(20) << "Name" << setw(15) << "Phone" << endl;
    file << "----------------------------------------" << endl;
  }
  for (long i = 0; i < persons.size(); ++i) {
    file << left << setw(20) << persons[i].name << setw(15) << persons[i].phone
         << endl;
  }
  file.close();
}

vector<Person> loadFromFile() {
  vector<Person> persons;
  ifstream file("directory.txt");
  string line;
  getline(file, line); // Skip header
  getline(file, line); // Skip separator
  while (getline(file, line)) {
    istringstream iss(line);
    string name;
    long int phone;
    iss >> setw(20) >> name >> setw(15) >> phone;
    persons.push_back(Person(name, phone));
  }
  file.close();
  return persons;
}

int main() {
  int n;
  cout << "Enter the number of users: ";
  cin >> n;
  vector<Person> persons(n);

  for (int i = 0; i < n; i++) {
    string name;
    long int phone;
    cout << "Enter the name of the user "<<i+1<<": ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter the phone number of the user: ";
    cin >> phone;
    persons[i] = Person(name, phone);
  }

  saveToFile(persons);

  while (true) {
    cout << "Choose an option:\n1. Search\n2. Update\n3. Exit\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
      string searchName;
      cout << "Enter the name to search: ";
      cin.ignore();
      getline(cin, searchName);
      bool found = false;
      ifstream file("directory.txt");
      string line;
      getline(file, line); // Skip header
      getline(file, line); // Skip separator
      while (getline(file, line)) {
        istringstream iss(line);
        string name;
        long int phone;
        iss >> setw(20) >> name >> setw(15) >> phone;
        if (name == searchName) {
          cout << "Name: " << name << ", Phone: " << phone << endl;
          found = true;
          break;
        }
      }
      file.close();
      if (!found) {
        cout << "User not found." << endl;
      }
    } else if (choice == 2) {
      string updateName;
      cout << "Enter the name to update: ";
      cin >> updateName;
      bool found = false;
      // persons = loadFromFile();
      ifstream file("directory.txt");
      ofstream tempFile("temp.txt");
      string line;
      getline(file, line); // Skip header
      tempFile << line << endl;
      getline(file, line); // Skip separator
      tempFile << line << endl;
      while (getline(file, line)) {
        istringstream iss(line);
        string name;
        long int phone;
        iss >> setw(20) >> name >> setw(15) >> phone;
        if (name == updateName) {
          cout << "Enter the new phone number: ";
          cin >> phone;
          found = true;
        }
        tempFile << left << setw(20) << name << setw(15) << phone << endl;
      }
      file.close();
      tempFile.close();
      remove("directory.txt");
      rename("temp.txt", "directory.txt");

      if (found) {
        cout << "Phone number updated." << endl;
      } else {
        cout << "User not found." << endl;
      }
    } else if (choice == 3) {
      break;
    } else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }

  return 0;
}