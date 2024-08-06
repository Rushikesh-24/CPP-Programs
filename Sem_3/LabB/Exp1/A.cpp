#include <iostream>
using namespace std;
class Student {
private:
  int subject_marks[4];
  string Name;
  string branch;
  float Percentage;

public:
Student (){
    Percentage=0.0;
}
void display(){
    cout<<"Name : "<<Name<<endl;
    cout<<"Branch : "<<branch<<endl;
}
  float percentage(){
    for(int i=0; i<4; i++){
        Percentage += subject_marks[i];
    }
    return Percentage/4;
  }
  void getmarks() {
    cout << "Enter the marks of the students" << endl;
    for (int i = 0; i < 4; i++) {
      cout<<"Subject "<<i+1<<" marks : ";
      cin >> subject_marks[i];
      if(subject_marks[i]>100){
        subject_marks[i] = 100;
      }
    }
  }
  void getdetails(){
    cout<<"Enter the details of the students" << endl;
    cout<<"Name : ";
    cin>>Name;
    cin.ignore();
    cout<<"Branch : ";
    cin>>branch;
    cin.ignore();
  };
};
int main() {
  int n;
  cout << "Enter the total number of students : ";
  cin >> n;
  cin.ignore();
  Student classA[n];
  for (int i = 0; i < n; i++) {
    classA[i].getdetails();
    classA[i].getmarks();
  }
  for (int i = 0; i < n; i++) {
    classA[i].display();
    cout <<"Student "<<i+1<<endl;
    cout<<"Percentage "<<classA[i].percentage()<<"%"<<endl;
  }
  return 0;
}