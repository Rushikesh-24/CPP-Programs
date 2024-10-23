#include <ctime>
#include <iomanip>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

string generateBillNo() {
  static random_device rd;
  static mt19937 gen(rd());
  static uniform_int_distribution<> dis(1000, 9999);

  ostringstream oss;
  oss << "FARM_" << dis(gen);
  return oss.str();
}
string convertToWords(float num) {
  // Function to convert a number to words
  // This is a simplified version and may not cover all cases
  const string ones[] = {"",     "One", "Two",   "Three", "Four",
                         "Five", "Six", "Seven", "Eight", "Nine"};
  const string teens[] = {"Ten",      "Eleven",  "Twelve",  "Thirteen",
                          "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                          "Eighteen", "Nineteen"};
  const string tens[] = {"",      "",      "Twenty",  "Thirty", "Forty",
                         "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
  const string thousands[] = {"", "Thousand", "Million", "Billion"};

  if (num == 0)
    return "Zero";

  int intPart = static_cast<int>(num);
  int decimalPart = static_cast<int>((num - intPart) * 100);

  string words = "";
  int place = 0;

  while (intPart > 0) {
    if (intPart % 1000 != 0) {
      string chunk = "";
      int n = intPart % 1000;
      if (n >= 100) {
        chunk += ones[n / 100] + " Hundred ";
        n %= 100;
      }
      if (n >= 20) {
        chunk += tens[n / 10] + " ";
        n %= 10;
      } else if (n >= 10) {
        chunk += teens[n - 10] + " ";
        n = 0;
      }
      if (n > 0) {
        chunk += ones[n] + " ";
      }
      words = chunk + thousands[place] + " " + words;
    }
    intPart /= 1000;
    place++;
  }

  if (decimalPart > 0) {
    words += "and " + to_string(decimalPart) + "/100";
  }

  return words;
}
float totalCharge = 0;
enum type { AC, NON_AC };
void dotedlines(bool line) {
  cout << "│" << setw(15) << (line ? "│" : "⎽")
       << "⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽"
          "⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽"
          "⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽"
       << (line ? "│" : "⎽") << "            │" << endl;
}
class Room {
  type x;
  string room_no;
  int adults, children, no_of_days, rate;
  int year, month, day;

public:
  Room() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    room_no = "";
    x = NON_AC;
    adults = 0;
    children = 0;
    no_of_days = 0;
    rate = 0;
  }
  Room(string r_no, type b, int a, int c, int n_days, int r) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    year = 1900 + ltm->tm_year;
    month = 1 + ltm->tm_mon;
    day = ltm->tm_mday;
    room_no = r_no;
    x = b;
    adults = a;
    children = c;
    no_of_days = n_days;
    rate = r;
    totalCharge += no_of_days * rate;
  }
  void input() {
    cout << "Enter Room No: ";
    cin >> room_no;
    cout << "Enter Type: ";
    int temp;
    cout << "Enter Type (0 for AC, 1 for NON_AC): ";
    cin >> temp;
    x = static_cast<type>(temp);
    cout << "Enter No of Adults: ";
    cin >> adults;
    cout << "Enter No of Children: ";
    cin >> children;
    cout << "Enter No of Days: ";
    cin >> no_of_days;
    cout << "Enter Rate: ";
    cin >> rate;
    totalCharge+=rate*no_of_days;
  }
  void display() {
    cout << "│" << setw(15) << "│" << setw(7) << left << room_no << setw(12)
         << left << (x == 0 ? "  AC" : "  NON-AC") << setw(10) << right
         << adults << setw(14) << right << children << " "
         << (day < 10 ? "0" : "") << day << "/" << (month < 10 ? "0" : "")
         << month << "/" << year << "   "
         << " " << (day + no_of_days < 10 ? "0" : "") << (day + no_of_days)
         << "/" << (month < 10 ? "0" : "") << month << "/" << year << right
         << setw(8) << no_of_days << setw(10) << right << fixed
         << setprecision(2) << (float)rate << left << setw(10) << right
         << (float)rate * no_of_days << "│" << setw(15) << "│" << endl;
    dotedlines(true);
  }
};
void display2(string lefttext, float righttext) {
  cout << "│" << setw(13) << " " << left << setw(38) << lefttext << setw(58)
       << right << righttext << setw(16) << "│" << endl;
  dotedlines(false);
}

int main() {
  time_t now = time(0);
  tm *ltm = localtime(&now);

  int year = 1900 + ltm->tm_year;
  int month = 1 + ltm->tm_mon;
  int day = ltm->tm_mday;
  while (true) {
    int choice;
    cout << "\n--- Menu ---\n";
    cout << "1. Generate Bill\n";
    cout << "2. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
      int n;
      string Hotel_Name, Guest;
      cout << "Enter Hotel Name: ";
      cin.ignore();
      getline(cin, Hotel_Name);
      cout << "Enter Guest Name: ";
      getline(cin, Guest);
      cout << "Enter the number of Rooms";
      cin >> n;
      Room x[n];
      for (int i = 0; i < n; i++) {
        x[i].input();
      }
      string Bill_No = generateBillNo();
      // Header
      cout << endl << endl;
      cout << " " << setw(122) << setfill('_') << "" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(75) << setfill(' ') << "GOA TOURISM DEVELOPMENT"
           << setw(50) << right << "│" << endl;
      cout << "│" << setw(74) << right << "CORPORATION LTD - GOA" << setw(51)
           << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(74) << setfill(' ') << "FARMAGUDI RECIDENCY"
           << setw(51) << right << "│" << endl;
      cout << "│" << setfill('_') << setw(125) << right << "│" << endl;

      // Info
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(70) << "CASH BILL" << setw(55) << "│"
           << endl;
      cout << "│"
           << "  Hostel : " << setw(87) << left << Hotel_Name
           << "Bill No :" << setw(15) << Bill_No << "│" << endl;
      cout << "│"
           << "  Guest  : " << setw(87) << left << Guest
           << "Date    :" << (day < 10 ? "0" : "") << day << "/"
           << (month < 10 ? "0" : "") << month << "/" << year << setw(8)
           << right << "│" << endl;

      // Room
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(13) << right << "" << setw(97) << setfill('_')
           << right << " " << setfill(' ') << setw(15) << "│" << endl;
      cout << "│" << setw(15) << right << "│"
           << "       │                   │               │                    "
              "     "
              "│       "
              " │        │        │"
           << setfill(' ') << setw(15) << right << "│" << endl;
      cout << "│" << setw(15) << "│"
           << " Room  │ Type of the Room  │ No. of Person │      Period of "
              "Stay     "
              "│ No. "
              "of │  Rate  │ Amount │            │"
           << endl;
      cout << "│" << setw(15) << "│"
           << "       │                   "
              "│⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺│⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺│     "
              "   │        │        │            │"
           << endl;
      cout << "│" << setw(15) << "│"
           << "       │                   │Adult  Children│ From               "
              "  To "
              "│  Days "
              " │        │        │            │"
           << endl;
      cout
          << "│" << setw(15) << "│"
          << "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
             "‾‾‾‾‾‾‾‾‾‾‾‾‾‾"
             "‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾│            │"
          << endl;
      for (int i = 0; i < n; i++) {
        x[i].display();
      }
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      display2("Total Room Charges", totalCharge);
      display2("Other Service Charge", totalCharge);
      display2("Cancellation Charges", totalCharge);
      display2("Luxury Tax ", totalCharge);
      display2("Service Tax", totalCharge);
      display2("C.E.S.T", totalCharge);
      display2("Other Tax", totalCharge);
      display2("Discount Amount", totalCharge);
      display2("Final Total", totalCharge);
      display2("Balance Amount", totalCharge);
      cout << "│" << setw(13) << " " << left << setw(38) << "Rupees "
           << setw(60) << right << convertToWords(totalCharge) << setw(14)
           << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(13) << " " << left << setw(38) << "Remarks"
           << setw(58) << right << "" << setw(16) << "│" << endl;
      dotedlines(false);
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(35) << right << "________________________" << setw(75)
           << setfill(' ') << "__________________" << setw(15) << "│" << endl;
      cout << "│" << setw(40) << right << "(Signature of the Receptionist)"
           << setw(70) << setfill(' ') << "(Signature of Guest)" << setw(15)
           << "│" << endl;
      cout << "│" << setfill(' ') << setw(125) << right << "│" << endl;
      cout << "│" << setw(125) << setfill('_') << "│" << endl;
      cout << "Bill generated successfully!\n";
      totalCharge=0;
    } else if (choice == 2) {
      cout << "Exiting...\n";
      break;
    } else {
      cout << "Invalid choice, please try again.\n";
    }
  }
}
