#include <iostream>
#include <stdexcept>
using namespace std;
void testExceptions(int value) {
    if (value == 0) {
        throw runtime_error("Runtime error: value is zero");
    } else if (value < 0) {
        throw invalid_argument("Invalid argument: value is negative");
    } else if (value > 100) {
        throw out_of_range("Out of range: value is greater than 100");
    } else {
        cout << "Value is acceptable: " << value << endl;
    }
}

int main() {
    int testValues[] = {50, 0, -10, 150};
    for (int i = 0; i < sizeof(testValues) / sizeof(testValues[0]); ++i) {
        try {
            testExceptions(testValues[i]);
        } catch (const runtime_error &e) {
            cout << "Caught a runtime_error: " << e.what() << endl;
        } catch (const invalid_argument &e) {
            cout << "Caught an invalid_argument: " << e.what() << endl;
        } catch (const out_of_range &e) {
            cout << "Caught an out_of_range: " << e.what() << endl;
        } catch (...) {
            cout << "Caught an unknown exception" << endl;
        }
    }
    return 0;
}

// Standard Library Exceptions:

// logic_error
// domain_error
// length_error
// out_of_range (already used in the code)
// range_error
// overflow_error
// underflow_error
// bad_alloc
// bad_cast
// bad_typeid
// bad_exception