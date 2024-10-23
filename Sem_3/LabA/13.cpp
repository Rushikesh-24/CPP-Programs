#include <iostream>
using namespace std;

const int SIZE = 5; // Global variable for array size

template <class T> class Sorter {
public:
  static void inputArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
      cin >> arr[i];
    }
  }
  static void sortArray(T arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
      for (int j = 0; j < size - i - 1; ++j) {
        if (arr[j] > arr[j + 1]) {
          T temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }
};

template <class T> void printArray(T arr[], int size) {
  for (int i = 0; i < size; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  int choice;
  cout << "Choose the type of array to sort:\n";
  cout << " 1. Integer\n";
  cout << " 2. Float\n";
  cout << " 3. String\n";
  cout << "-1. Exit\n";
  cout << "Enter your choice: ";
  cin >> choice;
  while (choice != -1) {
    switch (choice) {
    case 1: {
      int arr[SIZE];
      cout << "Enter " << SIZE << " integers: ";
      Sorter<int>::inputArray(arr, SIZE);
      Sorter<int>::sortArray(arr, SIZE);
      cout << "Sorted array: ";
      printArray(arr, SIZE);
      break;
    }
    case 2: {
      float arr[SIZE];
      cout << "Enter " << SIZE << " floats: ";
      Sorter<float>::inputArray(arr, SIZE);
      Sorter<float>::sortArray(arr, SIZE);
      cout << "Sorted array: ";
      printArray(arr, SIZE);
      break;
    }
    case 3: {
      string arr[SIZE];
      cout << "Enter " << SIZE << " strings: ";
      Sorter<string>::inputArray(arr, SIZE);
      Sorter<string>::sortArray(arr, SIZE);
      cout << "Sorted array: ";
      printArray(arr, SIZE);
      break;
    }
    default:
      cout << "Invalid choice!" << endl;
    }
    cout << "Choose the type of array to sort:\n";
    cout << " 1. Integer\n";
    cout << " 2. Float\n";
    cout << " 3. String\n";
    cout << "-1. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
  }
}