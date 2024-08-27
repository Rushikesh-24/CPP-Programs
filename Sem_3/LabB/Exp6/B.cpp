#include <iostream>
using namespace std;
class Shape {
public:
    virtual void calculateArea() = 0;
};

class Rectangle : public Shape {
public:
    void calculateArea() {
        int length, width;
        cout << "Enter length and width of the rectangle: ";
        cin >> length >> width;
        int area = length * width;
        cout << "Area of the rectangle: " << area << endl;
    }
};

class Circle : public Shape {
public:
    void calculateArea() {
        float radius;
        cout << "Enter radius of the circle: ";
        cin >> radius;
        float area = (22 * radius * radius)/7;
        cout << "Area of the circle: " << area << endl;
    }
};

int main() {
    Rectangle rectangle;
    Circle circle;
    rectangle.calculateArea();
    circle.calculateArea();

    return 0;
}