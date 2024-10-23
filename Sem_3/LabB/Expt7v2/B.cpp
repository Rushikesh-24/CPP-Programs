#include <iostream>
#include <string>

using namespace std;

void printPadded(int num, int width){
    string s = to_string(num);
    cout << "|  ";
    cout.width(width);
    cout.fill(' ');
    cout.setf(ios::right, ios::adjustfield);
    cout << s << "  ";
}

int main() {
    string line;
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;

    cout << "Enter your text (Ctrl + D to exit):\n";
    while (getline(cin, line)) {
        for(long i = 0; i < line.length(); ++i){
            char c = line[i];
            if(c == '\n'){
            lineCount++;
            charCount++;
            wordCount++;
            }
            else if(c == ' ' || c == '\t'){
            wordCount++;
            charCount++;
            }
            else{
            charCount++;
            }
        }
        lineCount++; // Count the last line if not empty
        wordCount++; // Count the last word if not empty
    }
    
    cout << "\nResults:\n";
    cout << "___________________________________________________________________\n";
    cout << "| Number of lines  |   Number of words   |  Number of characters  |\n";
    cout << "-------------------------------------------------------------------\n";
    printPadded(lineCount, 14);
    printPadded(wordCount, 17);
    printPadded(charCount, 20);
    cout << "|\n-------------------------------------------------------------------\n";
    cout << endl;
    return 0;
}