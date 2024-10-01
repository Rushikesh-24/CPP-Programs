#include<iostream>
using namespace std;
class FLOAT{
    float x;
    public:
    FLOAT(){
        x = 0.0;
    }
    FLOAT(float a){
        x = a;
    }
    float operator + (FLOAT f){
        return x + f.x;
    }
    float operator -(FLOAT f){
        return x - f.x;
    }
    float operator *(FLOAT f){
        return x * f.x;
    }
    float operator /(FLOAT f){
        return x/f.x;
    }
};
int main(){
    FLOAT a(10.5), b(20.5), c;
    cout << "Addition: " << a+b << endl;
    cout << "Subtration: "<<a-b <<endl;
    cout << "Multiplication: "<<a*b<<endl;
    cout << "Divisison: "<<a/b<<endl;
}