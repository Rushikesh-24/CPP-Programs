#include <iostream>
using namespace std;
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing a circle." << endl;
    }
};
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing a rectangle." << endl;
    }
};

int main() {
    Circle circle;
    Rectangle rectangle;
    circle.draw();
    rectangle.draw();
    return 0;
}