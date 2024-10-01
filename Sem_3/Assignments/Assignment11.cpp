#include<iostream>
using namespace std;
class student{
    protected:
    int roll_no;
    public:
    void get_roll_no(){
        cout<<"Enter the roll number: ";
        cin>>roll_no;
    }
};
class Test:public student{
    protected:
    int sub1,sub2;
    public:
    void get_marks(){
        cout<<"Enter the marks of subject 1: ";
        cin>>sub1;
        cout<<"Enter the marks of subject 2: ";
        cin>>sub2;
    }
};
class Result:public Test{
    protected:
    int total;
    public:
    void display(){
        total=sub1+sub2;
        cout<<"Roll number: "<<roll_no<<endl;
        cout<<"Subject 1: "<<sub1<<endl;
        cout<<"Subject 2: "<<sub2<<endl;
        cout<<"Total marks: "<<total<<endl;
    }
};
int main(){
    Result r;
    r.get_roll_no();
    r.get_marks();
    r.display();
    return 0;
}
