#include<iostream>
#include<fstream>
#include <vector>
#include <algorithm>
using namespace std;

void writeToFile(const string& filename, const vector<int>& elements) {
    ofstream file(filename);
    for (long i = 0; i < elements.size(); ++i) {
        file << elements[i] << " ";
    }
    file.close();
}

vector<int> readFromFile(const string& filename) {
    ifstream file(filename);
    vector<int> elements;
    int element;
    while (file >> element) {
        elements.push_back(element);
    }
    file.close();
    return elements;
}

void mergeFiles(const string& file1, const string& file2, const string& outputFile) {
    vector<int> elements1 = readFromFile(file1);
    vector<int> elements2 = readFromFile(file2);
    vector<int> mergedElements(elements1.begin(), elements1.end());
    mergedElements.insert(mergedElements.end(), elements2.begin(), elements2.end());
    sort(mergedElements.begin(), mergedElements.end());
    writeToFile(outputFile, mergedElements);
}

int main() {
    vector<int> elements1;
    vector<int> elements2;
    int n, element;

    cout << "Enter number of elements for the first file: ";
    cin >> n;
    cout << "Enter elements for the first file: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        elements1.push_back(element);
    }

    cout << "Enter number of elements for the second file: ";
    cin >> n;
    cout << "Enter elements for the second file: ";
    for (int i = 0; i < n; ++i) {
        cin >> element;
        elements2.push_back(element);
    }

    writeToFile("file1.txt", elements1);
    writeToFile("file2.txt", elements2);

    mergeFiles("file1.txt", "file2.txt", "mergedFile.txt");

    return 0;
}