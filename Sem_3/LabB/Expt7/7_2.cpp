#include<iostream>
using namespace std;
class Polar{
    float angle,radius;
    public:
    Polar(){
        angle = radius = 0;
    }
    Polar(float a,float r){
        angle = a;
        radius = r;
    }
    Polar operator +(Polar p){
        Polar temp;
        float x1 = radius * cos(angle);
        float y1 = radius * sin(angle);
        float x2 = p.radius * cos(p.angle);
        float y2 = p.radius * sin(p.angle);
        temp.angle = atan((y1+y2)/(x1+x2));
        temp.radius = sqrt(((x1+x2)*(x1+x2))+((y1+y2)*(y1+y2)));
        return temp;
    }
    void display(){
        cout<<"Angle :"<<angle<<endl<<"Radius :"<<radius<<endl;
    }
};
int main(){
    Polar p1(30,5),p2(60,10),p3;
    p3 = p1 + p2;
    cout<<"P1"<<endl;
    p1.display();
    cout<<"P2"<<endl;
    p2.display();
    cout<<"P3"<<endl;
    p3.display();
}