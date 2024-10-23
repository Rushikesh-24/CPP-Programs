#include <iostream>
using namespace std;
template<class T>
void mySwap(T &x, T &y){
    cout<<"Before Swapping A = "<<x<<" B = "<<y<<endl;
    T temp = x;
    x = y;
    y = temp;
    cout<<"After Swapping A = "<<x<<" B = "<<y<<endl;
}
int main(){
    int a = 10;
    int b = 20;
    mySwap(a, b);
    float c=1.1;
    float d= 1.2;
    mySwap(c, d);
    char e ='R';
    char f = 'G';
    mySwap(e, f);
}