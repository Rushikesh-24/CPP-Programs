#include <iomanip>
#include <iostream>
using namespace std;

class Cricketer {
    string name;
    long int runs;
    int innings;
    int times_not_out;
    double avg;

public:
    Cricketer() {
        name = "";
        runs = 0;
        innings = 0;
        times_not_out = 0;
        avg = 0;
    }

    void input() {
        cout << "Enter the name of the cricketer: ";
        cin >> name;
        cout << "Enter the number of runs scored: ";
        cin >> runs;
        cout << "Enter the number of innings played: ";
        cin >> innings;
        cout << "Enter the number of times not out: ";
        cin >> times_not_out;
    }

    void calculate() {
        avg = (float)runs / (innings - times_not_out);
    }

    void display() {
        cout << setw(15) << left << name
             << setw(10) << runs
             << setw(10) << innings
             << setw(15) << times_not_out
             << setw(10) << fixed << setprecision(2) << avg
             << endl;
    }
};

int main() {
    int n;
    cout << "Enter the number of cricketers: ";
    cin >> n;
    Cricketer team1[n];

    for (int i = 0; i < n; i++) {
        team1[i].input();
        team1[i].calculate();
    }

    cout << setw(15) << left << "Player's name"
         << setw(10) << "Runs"
         << setw(10) << "Innings"
         << setw(15) << "Times Not Out"
         << setw(10) << "Average"
         << endl;

    for (int i = 0; i < n; i++) {
        team1[i].display();
    }

    return 0;
}
