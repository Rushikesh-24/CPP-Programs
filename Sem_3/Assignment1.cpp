#include <iostream>
using namespace std;
struct Employee
{
    string Name;
    int Id;
    string Address;
};
int main()
{
    int number_of_employees, idSearch, flag = 0;
    string nameSearch;
    cout << endl
         << "Enter the number of Employees in your company : ";
    cin >> number_of_employees;

    struct Employee Company1[number_of_employees];
    cout << endl
         << "Enter the Details of the Company Employees " << endl
         << endl;
    for (int i = 0; i < number_of_employees; i++)
    {
        cout << "Enter the Details of Employee " << i << endl;
        cout << "Name        :";
        cin >> Company1[i].Name;
        cout << "Address     :";
        cin >> Company1[i].Address;
        cout << "Employee_Id :";
        cin >> Company1[i].Id;
        cout << endl;
    }
    cout << endl
         << "Employees Search" << endl;
    int a;
    do
    {
        cout << "Enter\n1 to search by Employee Id \n2 to search by Address\n3 to exit" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            cout << endl
                 << "Enter the Id of the employee you want to search :";
            cin >> idSearch;
            for (int i = 0; i < number_of_employees; i++)
            {
                if (Company1[i].Id == idSearch)
                {
                    cout << endl
                         << "Employee Found" << endl;
                    cout << "Name        :" << Company1[i].Name << endl;
                    cout << "Address     :" << Company1[i].Address << endl;
                    cout << "Employee_Id :" << Company1[i].Id << endl;
                }
            }
            break;
        case 2:
            cout << endl
                 << "Enter the Address of the employee you want to search :";
            cin >> nameSearch;
            for (int i = 0; i < number_of_employees; i++)
            {
                if (Company1[i].Address == nameSearch)
                {
                    cout << endl
                         << "Employee Found" << endl;
                    cout << "Name        :" << Company1[i].Name << endl;
                    cout << "Address     :" << Company1[i].Address << endl;
                    cout << "Employee_Id :" << Company1[i].Id << endl;
                }
            }
            break;
        case 3:
            cout << endl
                 << "Exit";
        default:
            cout << "Invalid choice ";
            break;
        }

    } while (a != 3);
    return 0;
}