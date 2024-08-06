#include <iostream>
#include <cmath>
using namespace std;

double calculate_sin(double x) {
    double term = x;
    double sin_x = term;
    int n = 1;
    const double precision = 0.000001;

    while (term > precision || term < -precision) {
        n += 2;
        term *= -x * x / (n * (n - 1));
        sin_x += term;
    }
    return sin_x;
}

int main() {
    double x;
    cout << "Enter the value of x (in degrees): ";
    cin >> x;

     double x_radians = x * M_PI / 180.0;
    double result = calculate_sin(x_radians);
    cout << "sin(" << x << "degrees) = " << result << endl;

    return 0;
}
