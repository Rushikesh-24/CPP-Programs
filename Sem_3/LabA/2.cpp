#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cout<<"Enter the number of rows and coloums";
    cin>>m>>n;
    cout<<"Enter the elements";
    char arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    string str;
    cout<<"Enter the string you want to search ";
    cin>> str;
    int flag=str.length();
    for(int k=0;k<str.length();k++){
        for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(str[k]==arr[i][j])
            {
                flag--;
                cout<<str[k]<<" found at position"<<i+1<<","<<j+1;
                cout<<endl;
            }
        }
    }
    }
    if(flag<=0)
    {
        cout<<"The complete strign is found";
    }
    else{
        cout<<"String not found in the array";
    }
    return 0;
}