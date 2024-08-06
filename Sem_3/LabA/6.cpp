#include <iomanip>
#include<iostream>
#include <string>
using namespace std;
class Address{
    string street;
    string city;
    public:
    void getAddress(){
        cout<<"Enter the street :";
        getline(cin, street);
        cout<<"Enter the city :";
        getline(cin,city);
    }
    string streetDisplay(){
        return street;
    }
    string cityDisplay(){
        return city;
    }
};
class Person{
    Address address;
    string name;
    public:
    friend void  printPersonDetails(Person & person);
    void getData(){
        cout<<"Enter name :";
        getline(cin, name);
        address.getAddress();
    }
};
void printPersonDetails(Person & person){
    cout<<setw(10)<<"Person :"<<person.name<<endl<<setw(10)<<"Street :"<<person.address.streetDisplay()<<endl<<setw(10)<<"City :"<<person.address.cityDisplay()<<endl;
}
int main(){
    Person person;
    person.getData();
    printPersonDetails(person);
    return 0;
}