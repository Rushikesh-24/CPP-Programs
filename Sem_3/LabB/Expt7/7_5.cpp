#include <iostream>
using namespace std;
class Rectangle;

class Polar {
  float radius, angle;

public:
  Polar(float r, float a) : radius(r), angle(a) {}
  Polar(Rectangle r);
  Polar() { radius = angle = 0; }

  float getRadius() const { return radius; }
  float getAngle() const { return angle; }

  void display() const {
    cout << "Polar Coordinates: Radius = " << radius << ", Angle = " << angle << endl;
  }
};

class Rectangle {
  float x, y;

public:
  Rectangle() { x = y = 0; }
  Rectangle(float x1, float y1) : x(x1), y(y1) {}
  Rectangle(Polar p);

  float getX() const { return x; }
  float getY() const { return y; }

  void display() const {
    cout << "Rectangle Coordinates: X = " << x << ", Y = " << y << endl;
  }
};

Polar::Polar(Rectangle r) {
  radius = sqrt(r.getX() * r.getX() + r.getY() * r.getY());
  angle = atan(r.getY() / r.getX());
}

Rectangle::Rectangle(Polar p) {
  x = p.getRadius() * cos(p.getAngle());
  y = p.getRadius() * sin(p.getAngle());
}

int main() {
  float x1, y1, x2, y2;
  cout << "For Polar enter the Angle and Radius: ";
  cin >> x1 >> y1;
  Polar p1(x1, y1), p2;
  cout << "For Rectangle enter the X and Y: ";
  cin >> x2 >> y2;
  Rectangle r1(x2, y2), r2;
  cout << "Original Rectangle:" << endl;
  r1.display();
  cout << "Original Polar:" << endl;
  p1.display();
  Polar p3(r1);
  cout << "Converted Polar from Rectangle:" << endl;
  p3.display();
  Rectangle r3(p1);
  cout << "Converted Rectangle from Polar:" << endl;
  r3.display();

  return 0;
}