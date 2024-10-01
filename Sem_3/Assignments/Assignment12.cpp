#include <iostream>
#include <string>
using namespace std;

enum acc_type { savings, current };

class account {
protected:
  string name;
  int acc_no;
  double balance;
  acc_type type;

public:
  void initialize(string cust_name, int account_no, acc_type account_type,double initial_balance) {
    name = cust_name;
    acc_no = account_no;
    type = account_type;
    balance = initial_balance;
  }

  void deposit(double amount) {
    balance += amount;
    cout << "Deposit successful. Updated balance: " << balance << endl;
  }

  void display_balance() {
    cout << "Account No: " << acc_no << endl;
    cout << "Customer Name: " << name << endl;
    cout << "Current Balance: " << balance << endl;
  }

  virtual void withdraw(double amount) = 0;
  virtual void check_minimum_balance() = 0;
};

class current_account : public account {
private:
public:
  void withdraw(double amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << "Withdrawal successful. Updated balance: " << balance << endl;
    } else {
      cout << "Insufficient balance." << endl;
    }
  }

  void check_minimum_balance() {
    if (balance < 500.0) { // 500.0 is minimum balance
      balance -= 100.0;    // 100.0 is penalty
      cout << "Balance below minimum. Penalty of " << 100.0
           << " imposed. Updated balance: " << balance << endl;
    } else {
      cout << "Balance is above the minimum required." << endl;
    }
  }
};

class savings_account : public account {
public:
  void deposit_interest() {
    double interest = balance * 0.04; // 0.04 is interest rate
    balance += interest;
    cout << "Interest of " << interest << " added. Updated balance: " << balance
         << endl;
  }

  void withdraw(double amount) {
    if (balance >= amount) {
      balance -= amount;
      cout << "Withdrawal successful. Updated balance: " << balance << endl;
    } else {
      cout << "Insufficient balance." << endl;
    }
  }

  void check_minimum_balance() {
    cout << "No minimum balance requirement for savings account." << endl;
  }
};

int main() {
  current_account currentAcc;
  currentAcc.initialize("Rushikesh Gaonkar", 123456, current, 600.0);
  currentAcc.deposit(200.0);
  currentAcc.display_balance();
  currentAcc.withdraw(400.0);
  currentAcc.check_minimum_balance();

  savings_account savingsAcc;
  savingsAcc.initialize("Sanish Pagui", 654321, savings, 1000.0);
  savingsAcc.deposit_interest();
  savingsAcc.display_balance();
  savingsAcc.withdraw(200.0);
  savingsAcc.check_minimum_balance();

  return 0;
}
