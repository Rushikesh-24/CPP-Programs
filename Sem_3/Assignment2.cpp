#include <iostream>
using namespace std;
struct Customers
{
    string Name;
    int Units;
    float Cost;
};
float BillCalculator(int units)
{
    float Price;
    if (units <= 100)
    {
        Price = units * 0.6;
    }
    else if (units <= 200)
    {
        Price = (units - 100) * 0.8 + 60;
    }
    else if (units <= 300)
    {
        Price = 60 + 80 + (units - 200) * 0.9;
    }
    if (Price < 50)
    {
        return 50.0;
    }
    else if (Price > 300)
    {
        Price += Price * 0.15;
    }
    return Price;
}
int main()
{
    int number_of_customers;
    cout << "Enter the number of customers :";
    cin >> number_of_customers;
    struct Customers CompanyA[number_of_customers];
    cout << "Enter the Details Of The Customers" << endl;
    for (int i = 0; i < number_of_customers; i++)
    {
        cout << endl
             << "Enter the Name of the Customer : ";
        cin >> CompanyA[i].Name;
        cout << endl
             << "Enter the Units of the Customer : ";
        cin >> CompanyA[i].Units;
        CompanyA[i].Cost = BillCalculator(CompanyA[i].Units);
    }
    cout << endl
         << "The Bill of the Customers";
    for (int i = 0; i < number_of_customers; i++)
    {
        cout << endl
             << "Customer " << i << endl;
        cout << "Name  : " << CompanyA[i].Name << endl;
        cout << "Units : " << CompanyA[i].Units << endl;
        cout << "Cost  : " << CompanyA[i].Cost << endl;
    }
    return 0;
}