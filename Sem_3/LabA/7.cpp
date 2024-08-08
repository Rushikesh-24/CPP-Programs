#include <algorithm>
#include <iostream>
using namespace std;
void wrongGuess(string a) {
  cout << "Sorry, you lose. You chose the " << a << endl;
}
void correct() { cout << "You win" << endl; }
class cards {
  string card_name;
  int value;
public:
  cards() {
    value = 0;
    card_name = "NULL";
  }
  cards(int v, string n) {
    value = v;
    card_name = n;
  }
  cards(cards &x) {
    value = x.value;
    card_name = x.card_name;
  }
  int valueReturnt() { return value; }
  void display() {
    cout << "Card " << value << " is the " << card_name << endl;
  }
  friend void swap(cards &x , cards &y, cards &z);
  friend int guess(int,cards &x , cards &y, cards &z);
  ~cards() { cout << "Destructor called" << endl; }
};
void swap(cards &x , cards &y, cards &z) { 
  int r,s;
  cout<<"Enter the card you want to swap for example (1 2) : ";
  cin>>r>>s;
  system("clear");
  if(r==1 && s==2){
    string temp;
    temp = x.card_name;
    x.card_name = y.card_name;
    y.card_name =  temp;
  }
  if (r == 1 && s == 3) {
    string temp;
    temp = x.card_name;
    x.card_name = z.card_name;
    z.card_name = temp;
  } else if (r == 2 && s == 3) {
    string temp;
    temp = y.card_name;
    y.card_name = z.card_name;
    z.card_name = temp;
  } else if (r == 3 && s == 1) {
    string temp;
    temp = z.card_name;
    z.card_name = x.card_name;
    x.card_name = temp;
  } else if (r == 3 && s == 2) {
    string temp;
    temp = z.card_name;
    z.card_name = y.card_name;
    y.card_name = temp;
  }
}
int guess(int i,cards &x , cards &y, cards &z){
  int test;
  cout<<"User 1 "<<endl;
  cout<<"Now where (1,2,3) is the ace of spades :";
  cin>>test;
  if(test == x.value && x.card_name == "ace of spades") {
    return 1;
  }
  else if(test == y.value && y.card_name == "ace of spades"){
    return 1;
  }
  else if(test == z.value && z.card_name == "ace of spades"){
    return 1;
  }
  else if (test >=1 && test <=3){
    cout<<endl<<"Wrong guess"<<endl<<endl;
    cout<<"Current Cards position : 1: "<<x.card_name<<" | 2:"<<y.card_name<<" | 3:"<<z.card_name<<endl;
    return 0;
  }
  else{
    cout<<"Invalid guess"<<endl;
    return 0;
  }
}
int main() {
  int flag = 0, i=2;
  cards a(1, "7 of clubs"), b(2, "Jack of hearts"), c(3, "ace of spades");
  a.display();
  b.display();
  c.display();
  do{
    i=i==1?2:1;
    swap(a,b,c);
    flag = guess(i,a,b,c);
  }while(flag == 0 );
  cout<<"User "<<i<<" won"<<endl;
  return 0;
}