#include <iostream>
using namespace std;

int main() {
    int n,votes,spoilt=0;
    cout<<"Enter the number of people : ";
    cin>>n;
    int arr[5] = {0,0,0,0,0,};
        cout<<"Enter 1 to vote for candidate A"<<endl;
        cout<<"Enter 2 to vote for candidate B"<<endl;
        cout<<"Enter 3 to vote for candidate C"<<endl;
        cout<<"Enter 4 to vote for candidate D"<<endl;
        cout<<"Enter 5 to vote for candidate E";
    for(int i=0;i<n;i++){
        cout<<endl<<"Voter "<<i+1<<": ";
        cin>>votes;
        if(votes<6 && votes>0){
            arr[votes]++;
        }
        else{
            spoilt++;
        }
    }
    for(int i=0; i<5; i++){
        cout<<"Votes for candidate "<<char(65+i)<<" are : "<<arr[i]<<endl;
    }
    cout<<"Spoilt Votes are : "<<spoilt;

    return 0;
}