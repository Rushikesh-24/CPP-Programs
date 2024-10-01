#include <iostream>
using namespace std;
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
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
    Shape* shapePtr;
    Circle circle;
    Rectangle rectangle;

    shapePtr = &circle;
    shapePtr->draw();

    shapePtr = &rectangle;
    shapePtr->draw(); 

    return 0;
}