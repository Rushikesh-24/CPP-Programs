#include<iostream>
using namespace std;
class complex{
    int real,imaginary;
    public:
    complex(){
        real=0;
        imaginary=0;
    }
    complex(int r, int i){
        real = r;
        imaginary = i;
    }
    complex(complex & x){
        real =x.real;
        imaginary=x.imaginary;
    }
    ~complex(){
        cout<<"Destructor called"<<endl;
    }
    void display(){
        cout<<real<<" + "<<imaginary<<"i"<<endl;
    }
    friend complex summation(complex,complex);
};
complex summation(complex p1,complex p2){
    complex temp;
    temp.real = p1.real + p2.real;
    temp.imaginary = p1.imaginary + p2.imaginary;
    return temp;
}
int main(){
    complex a(1,2),b(1,2);
    complex c(b);
    c.display();
    c = summation(a, b);
    return 0;
}