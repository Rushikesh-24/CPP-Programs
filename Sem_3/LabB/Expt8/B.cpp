#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Vector {
private:
    //vector<T> vec;  
    T *arr;
    int size;

public:
    Vector(int size, T initialValue = T()) {
        //vec.resize(size, initialValue);
        this->size = size;
        arr = new T[size];
    }

    void modifyElement(int index, T newValue) {
        if (index >= 0 && index < size) {
            //vec[index] = newValue;
            arr[index] = newValue;
        } else {
            cout << "Error: Index out of bounds." << endl;
        }
    }

    void display(int size) const {
        cout << "Vector elements: ";
        for(int i = 0;i<size;i++){
            // cout<<vec[i]<<" ";
            cout<<arr[i]<<" ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the integer vector: ";
    cin >> size;

    Vector<int> intVector(size, 0);  

    intVector.modifyElement(0, 10);  
    intVector.modifyElement(1, 20); 

    intVector.display(size);

    Vector<double> doubleVector(size, 0.0);  

    doubleVector.modifyElement(0, 1.5); 
    doubleVector.modifyElement(2, 3.14); 

    doubleVector.display(size);

    return 0;
}