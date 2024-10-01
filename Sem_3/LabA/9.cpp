#include<iostream>
#include<cmath>
using namespace std;

class Shape{
    public:
    virtual void Area() = 0;
};

class Triangle: public Shape{
    protected:
    float base, height;
    
    public:
    Triangle(){
        base = 0;
        height = 0;
    }
    
    void getdata(){
        cout<<"Enter base: ";
        cin>>base;
        cout<<"Enter height: ";
        cin>>height;
    }
    
    void Area(){
        cout<<"Area of Triangle is: "<<0.5 * base * height <<endl;
    }
};

class RightAngleTriangle: public Triangle{
    public:
    void Area(){
        cout<<"Area of Right Angle Triangle is: "<<0.5 * base * height <<endl;
    }
};

class IsoscelesTriangle: public Triangle{
    public:
    void Area(){
        cout<<"Area of Isosceles Triangle is: "<<0.5 * base * height <<endl;
    }
};

class EquilateralTriangle: public Triangle{
    public:
    void Area(){
        cout<<"Area of Equilateral Triangle is: "<<(sqrt(3) / 4) * base * base <<endl;
    }
};

class Rectangle: public Shape{
    protected:
    float width, height;
    
    public:
    Rectangle(){
        width = 0;
        height = 0;
    }
    
    void getdata(){
        cout<<"Enter width: ";
        cin>>width;
        cout<<"Enter height: ";
        cin>>height;
    }
    
    void Area(){
        cout<<"Area of Rectangle is: "<<width * height <<endl;
    }
};

int main(){
    Shape *s;
    Triangle t;
    Rectangle r;
    RightAngleTriangle ra;
    IsoscelesTriangle iso;
    EquilateralTriangle eq;
    
    s = &t;
    t.getdata();
    s->Area();
    
    s = &r;
    r.getdata();
    s->Area();
    
    s = &ra;
    ra.getdata();
    s->Area();
    
    s = &iso;
    iso.getdata();
    s->Area();
    
    s = &eq;
    eq.getdata();
    s->Area();
    
    return 0;
}