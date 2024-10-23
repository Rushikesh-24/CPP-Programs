#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the total number you wnat to check : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the number :";
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int flag1 = 0,flag2 = 0;
        if (arr[i] % 2 == 0)
        {
             flag2=1;
        }
        else
        {
            flag2=0;
        }
        for (int k = 2; k < arr[i]; k++)
        {
            if (arr[i] % k == 0)
            {
                flag1 = 1;
            }
        }
        cout<<arr[i]<<" is ";
        if (flag1 == 1)
        {
            cout << "Non Prime ";
        }
        else
        {
            cout << "Prime ";
        }
        if (flag2 == 1)
        {
            cout << "and Even Number " << endl;
        }
        else
        {
            cout << "and Odd Number " << endl;
        }

    }
    return 0;
}