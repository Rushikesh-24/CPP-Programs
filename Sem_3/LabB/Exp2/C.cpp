#include <iostream>
using namespace std;
int add(int a, int b) {
    return a + b;
}
int add(int a, int b, int c) {
    return a + b + c;
}

float add(float a, float b) {
    return a + b;
}

int main() {
    int num1 = 5, num2 = 10, num3 = 15;
    float float1 = 2.5, float2 = 3.7;

    int result1 = add(num1, num2);
    int result2 = add(num1, num2, num3);
    float result3 = add(float1, float2);
    cout << "Result 1: " << result1 << endl;
    cout << "Result 2: " << result2 << endl;
    cout << "Result 3: " << result3 << endl;

    return 0;
}