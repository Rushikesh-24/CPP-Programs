#include<iostream>
using namespace std;
class Worker{
    protected:
    int worker_id;
    string name;
    string address;
    int department_id;
    int supervisor_id;
    public:
    void get_worker_details(){
        cout<<"Enter the worker id: ";
        cin>>worker_id;
        cin.ignore();
        cout<<"Enter the name: ";
        getline(cin, name);
        cout<<"Enter the address: ";
        getline(cin, address);
        cout<<"Enter the department id: ";
        cin>>department_id;
        cout<<"Enter the supervisor id: ";
        cin>>supervisor_id;
    }
     virtual void print_details() {
        cout << "Worker ID: " << worker_id << endl;
        cout << "Name: " << name << endl;
        cout << "Supervisor ID: " << supervisor_id << endl;
    }
};
class Supervisor : public Worker {
public:
    void print_details() {
        cout << "Supervisor Name: " << name << endl;
        cout << "Department ID: " << department_id << endl;
    }
};
int main(){
    Worker w;
    cout<<"Enter Worker Details:"<<endl;
    w.get_worker_details();
    Supervisor s;
    cout<<"Enter Supervisor Details:"<<endl;
    s.get_worker_details();
    cout << "Worker Details:" << endl;
    w.print_details();
    cout << "\nSupervisor Details:" << endl;
    s.print_details();
    return 0;
}