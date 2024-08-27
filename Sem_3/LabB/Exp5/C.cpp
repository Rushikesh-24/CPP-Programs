#include<iostream>
using namespace std;
class A{
    protected:
    int a;
    public:
    A(int x){
        a = x;
        cout<<"A initialised"<<endl;
    }
};
class B{
    protected:
    int b;
    public:
    B(int x){
        b = x;
        cout<<"B initialised"<<endl;
    }
};
class C:public B,public A{
    protected:
    int c;
    public:
    C(int p,int q,int r):A(p),B(q){
        c=r;
        cout<<"C initialised"<<endl;
    }  
    void multiply(){
        cout<<c*a*b;
    }
};
int main(){
    C obj(1,2,3);
    obj.multiply();
    return 0;
}