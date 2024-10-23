#include<iostream>
using namespace std;
class MAT{
    int *m;
    int **n;
    int rows;
    int cols;
public:
    MAT(int r, int c){
        rows = r;
        cols = c;
        m = new int;
        *m = 0;
        n = new int*[rows];
        for(int i = 0; i < rows; i++){
            n[i] = new int[cols];
            for(int j = 0; j < cols; j++){
                n[i][j] = 0;
            }
        }
    }
    void insert(){
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                cout << "Enter element at [" << i << "][" << j << "]: ";
                cin >> n[i][j];
            }
        }
    }
     friend void operator>>(istream &c1, MAT &c){
            cout << "Enter elements in matrix: ";
            for(int i=0; i<c.rows; i++){
                for(int j=0; j<c.cols; j++){
                    c1 >> c.n[i][j];        
                }
            }
        }
        friend void operator<<(ostream &c1, MAT &c){
            c1 << "Matrix: \n";
            for(int i=0; i<c.rows; i++){
                for(int j=0; j<c.cols; j++){
                    c1 << c.n[i][j] << " ";           
                }
                c1 << endl;
            }
        }

    MAT operator +(MAT m){
        if(m.cols != cols || m.rows != rows){
            cout<<"Addition not possible";
            exit(1);
        }
        MAT temp(rows, cols);
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp.n[i][j] = n[i][j] + m.n[i][j];
            }
        }
        return temp;
    }

    MAT operator -(MAT m){
        if(m.cols != cols || m.rows != rows){
            cout<<"Subtraction not possible";
            exit(1);
        }
        MAT temp(rows, cols);
        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                temp.n[i][j] = n[i][j] - m.n[i][j];
            }
        }
        return temp;
    }

    MAT operator *(MAT x){
        if(cols != x.rows){
            cout<<"Multiplication not possible";
            exit(1);
        }
        MAT temp(rows, x.cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < x.cols; j++){
                for(int k = 0; k < cols; k++){
                    temp.n[i][j] += n[i][k] * x.n[k][j];
                }
            }
        }
        return temp;
    }
    MAT &operator *(int x){
        for(int i = 0 ;i<rows;i++){
            for(int j = 0; j<cols;j++){
                n[i][j] = n[i][j] * x;
            }
        }
        return *this;
    }
    void display(){
        for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << n[i][j] << " ";
        }
        cout << endl;
    }
    }
    
};
int main(){
    int r1, c1, r2, c2;
    cout << "Enter the number of rows and columns of matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter the number of rows and columns of matrix 2: ";
    cin >> r2 >> c2;
    MAT m1(r1, c1), m2(r2, c2), m3(r1, c2);
    cout << "Enter the elements of matrix 1: " << endl;
    m1.insert();
    cout << "Enter the elements of matrix 2: " << endl;
    m2.insert();
    cout<<"Matrix 1:"<<endl;
    cout<<m1;
    cout<<"Matrix 2:"<<endl;
    cout<<m2;
    m3 = m1 + m2;
    cout << "Addition: " << endl;
    cout<<m3;
    m3 = m1 - m2;
    cout << "Subtraction: " << endl;
    cout<<m3;
    m3 = m1 * m2;
    cout << "Multiplication: " << endl;
    cout<<m3;
    cout << "Multiplication with Scalar: " << endl;
    m3 = m1 * 2;
    cout<<m3;
    return 0;
}