#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of elements in the array"<<endl;
    cin>>n;
    int arry[n];
    cout<<"Enter the elements in the array";
    for(int i=0; i<n; i++){
        cin>>arry[i];
    }
    int low =arry[0];
    int high =arry[0];
    for(int i=0; i<n; i++){
        if(arry[i]<low){
            low = arry[i];
        }
        if(arry[i]>high){
            high=arry[i];
        }
    }
    cout<<"Difference between the highest anfd the lowest is :"<<high-low;
    return 0;
}