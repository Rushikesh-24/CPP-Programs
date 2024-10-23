#include <iostream>
using namespace std;

class Cards {
    string card_name;
    int value;
public:
    Cards(int v = 0, string n = "NULL") : value(v), card_name(n) {}
    int valueReturnt() const { return value; }
    string getName() const { return card_name; }
    void setName(string name) { card_name = name; }
    void display() const {
        cout << "Card " << value << " is the " << card_name << endl;
    }
    friend void swap(Cards &x, Cards &y);
    friend int guess(Cards &x, Cards &y, Cards &z);
    ~Cards() { cout << "Destructor called for " << card_name << endl; }
};

void swap(Cards &x, Cards &y) {
    std::swap(x.card_name, y.card_name);
}

int guess(Cards &x, Cards &y, Cards &z) {
    int test;
    cout << "Now where (1,2,3) is the ace of spades: ";
    cin >> test;

    if (test == x.valueReturnt() && x.getName() == "ace of spades") return 1;
    if (test == y.valueReturnt() && y.getName() == "ace of spades") return 1;
    if (test == z.valueReturnt() && z.getName() == "ace of spades") return 1;

    if (test >= 1 && test <= 3) {
        cout << endl << "Wrong guess" << endl << endl;
        cout << "Current Cards position: 1: " << x.getName() 
             << " | 2: " << y.getName() 
             << " | 3: " << z.getName() << endl;
        return 0;
    } else {
        cout << "Invalid guess" << endl;
        return 0;
    }
}

int main() {
    int flag = 0, currentUser = 2;
    Cards a(1, "7 of clubs"), b(2, "Jack of hearts"), c(3, "ace of spades");

    a.display();
    b.display();
    c.display();

    do {
        currentUser = currentUser == 1 ? 2 : 1;
        int r, s;
        cout << "User " << currentUser << " turn to swap." << endl;
        cout << "Enter the cards you want to swap (e.g., 1 2): ";
        cin >> r >> s;
        system("clear");

        if (r == 1 && s == 2) swap(a, b);
        else if (r == 1 && s == 3) swap(a, c);
        else if (r == 2 && s == 3) swap(b, c);
        else {
            cout << "Invalid swap choice." << endl;
            continue;
        }

        flag = guess(a, b, c);

    } while (flag == 0);

    cout << "User " << currentUser << " won!" << endl;

    return 0;
}
