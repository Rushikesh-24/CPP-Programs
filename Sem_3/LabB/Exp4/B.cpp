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
        cout<<a<<endl;
    }
};
int main(){
    test x(25),y(20);
    cout<<"Initial Values "<<endl<<"x : ";
    x.display();
    cout<<"y : ";
    y.display();
    x = 5 + y;
    cout<<"5 + y = ";
    x.display();
    x = x * y;
    cout<<"x * y = ";
    x.display();
    x = y - 5;
    cout<<"y - 5 = ";
    x.display();
}