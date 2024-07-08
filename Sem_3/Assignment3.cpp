#include<iostream>
using namespace std;
int main() {
    int num;
    cout<<"Enter the number of rows :";
    cin>>num;
    int n1 = 1,n2=1,temp;
    for (int i = 0; i < num; i++) { 
        int nextTerm = n1;
        for(int j = 0; j <= i; j++){
                cout<<n1<<" ";
                temp=n2+n1;
                n1=n2;
                n2=temp;
        }
        cout<<endl;
        n1=1;n2=1;
    }
    return 0;
}