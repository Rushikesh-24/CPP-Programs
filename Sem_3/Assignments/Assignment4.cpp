#include<iostream>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of rows and columns in this 2D matrix : ";
    cin>>m>>n;
    if(m!=n){
        cout<<"Diagonals of only a square matric can be changed";
        return 0;
    }
    int a[n][n];
    cout<<"Enter the element of the matrix"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a[i][j];
        }
    }
    cout<<"Before changing"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"After chnaging"<<endl;
    for(int i=0; i<n; i++){
        int temp = a[i][i];
        a[i][i] = a[i][n - i - 1];
        a[i][n - i - 1] = temp;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}