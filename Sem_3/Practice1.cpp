#include <iostream>
using namespace std;
struct node
{
    int item;
    struct node *link;
};
struct node *convertToLL(struct node *start, int arr[], int n)
{
    if (n == 0) return nullptr;

    struct node *p = nullptr, *q = nullptr;
    
    start = new struct node;
    start->item = arr[0];
    start->link = nullptr;
    q = start;

    for (int i = 1; i < n; i++) {
        p = new struct node;
        p->item = arr[i];
        p->link = nullptr;
        q->link = p;
        q = p;
    }

    return start;
}
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        cout << "\nList is empty";
        return;
    }
    p = start;
    cout << "Contents of the list are:"<<endl;
    while (p != NULL)
    {
        cout << p->item;
        cout<<" "<<p->link<<endl;
        p = p->link;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Enter the number of elements of the array :";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    struct node *start = NULL;
    start = convertToLL(start, arr, n);
    display(start);
    return 0;
}