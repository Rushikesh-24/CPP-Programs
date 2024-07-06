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
    int r=0;
    cout<<"Enter the string you want to search ";
    cin>> str;
    int flag=str.length();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(str[r]==arr[i][j])
            {
                if(r>=str.length()){
                    break;
                }
                flag--;
                cout<<str[r]<<" found at position"<<i+1<<","<<j+1;
                cout<<endl;
                r++;
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