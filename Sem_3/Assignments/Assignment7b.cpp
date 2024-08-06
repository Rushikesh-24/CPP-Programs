#include <iostream>
#include <cmath>
using namespace std;
double calculate_sum(int max_terms) {
    long double sum = 1.0;
    double term;
    const long double precision = 0.000001;
    int n = 2;

    do {
        term = pow(1.0 / n, n);
        sum += term;
        n++;
    } while (term > precision && (n - 2) < max_terms);

    return sum;
}

int main() {
    int max_terms;
    cout << "Enter the number of terms to consider (max_terms): ";
    cin >> max_terms;

    long double result = calculate_sum(max_terms);
    cout << "The sum of the series is: " << result << endl;

    return 0;
}