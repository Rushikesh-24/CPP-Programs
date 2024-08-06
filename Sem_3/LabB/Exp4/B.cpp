#include<iostream>
using namespace std;
class test{
    int a;
    public:
    test(){
        a=0;
    }
    test(int x){
        a=x;
    }
    friend test operator +(int b,test & a){
        test temp;
        temp.a=a.a+b;
        return temp;
    }
    friend test operator *(test & a,test & b){
        test temp;
        temp.a=a.a*b.a;
        return temp;
    }
    friend test operator -(test & a,int b){
        test temp;
        temp.a=a.a-b;
        return temp;
    }
    void display(){
        cout<<"Value :"<<a<<endl;
    }
};
int main(){
    test x(10),y(20);
    x.display();
    y.display();
    x = 5 + y;
    x.display();
    y.display();
    x = x * y;
    x.display();
    y.display();
    x = y - 5;
    x.display();
    y.display();
}