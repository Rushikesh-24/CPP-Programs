#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long double sum = 0;
    long double term = 1;
    int no_of_terms;
    cout << "Enter the number of terms: ";
    cin >> no_of_terms;
    int n = 1;
        while (n <= no_of_terms) {
        sum += term;
        n++;
        term = 1.0 / n;
        for (int i = 1; i < n; i++) {
            term *= 1.0 / n;
        }
    }
    cout<< fixed << setprecision(6);
    cout << "Sum = " << sum << endl;
    return 0;
}